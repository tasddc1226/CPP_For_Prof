#include "Logger.h"
#include <fstream>
#include <iostream>
#include <chrono>

using namespace std;

Logger::Logger()
{
	// ��׶��� �����带 �����Ѵ�.
	mThread = thread{ &Logger::processEntries, this };
}

Logger::~Logger()
{
	{
		//unique_lock lock(mMutex);  // C++17
		unique_lock<mutex> lock(mMutex);
		// mExit�� true�� �����ϰ� �����忡 �˸��� ������ �����带 ���� �����Ų��.
		mExit = true;
		// ���� ������ �˸��� ������ �����带 �����.
		mCondVar.notify_all();
	}
	// �����尡 ����� ������ ��ٸ���. �� �κ��� �տ� ���� ��� �ۿ� �־� �Ѵ�.
	// join()�� ȣ���ϱ� ���� �ݵ�� ���� �����ؾ� �ϱ� �����̴�.
	mThread.join();
}

void Logger::log(string_view entry)
{
	// ���ؽ��� ���� �ɰ� ť�� �α� �׸��� �߰��Ѵ�.
	//unique_lock lock(mMutex);  // C++17
	unique_lock<mutex> lock(mMutex);
	mQueue.push(string(entry));

	// ���� ������ �˸��� ���� �����带 �����.
	mCondVar.notify_all();
}

void Logger::processEntries()
{
	// �α� ������ ����.
	ofstream logFile("log.txt");
	if (logFile.fail()) {
		cerr << "Failed to open logfile." << endl;
		return;
	}

	// ť ó�� �ݺ��� ����
	//unique_lock lock(mMutex);  // C++17
	unique_lock<mutex> lock(mMutex);
	while (true) {
		
		// Ư���� ������ �߻���Ű�� ���� ��Ƽ������� ����Ǵ� �ڵ��� ���� �κ��� ���� ������ų �� �ִ�.
		// ��, �̷� ���� �ڵ�� �׽�Ʈ �뵵�θ� ����ϰ�, ���� ���������� �����Ѵ�.
		//
		// ���� ��� Logger Ŭ������ �Ҹ��ڿ��� �߻��ϴ� ������ ������ 
		// 23�忡�� ������ ��Ĵ�� ������ �ذ�ƴ��� Ȯ���ϵ��� ������ ���� �ۼ��� �� �ִ�.
		//this_thread::sleep_for(1000ms); // Needs #include <chrono>

		if (!mExit) { // ������ �ʿ䰡 ���� ���� �˸��� ��ٸ���.
			// �˸��� ��ٸ���.
			mCondVar.wait(lock);
		}

		// ť�� �׸��� �߰��ǰų� �����带 �����ų ��Ȳ�� �߻��ϸ� ���� ������ �˸��� ���޵ȴ�.
		lock.unlock();
		while (true) {
			lock.lock();
			if (mQueue.empty()) {
				break;
			} else {
				logFile << mQueue.front() << endl;
				mQueue.pop();
			}
			lock.unlock();
		}

		if (mExit) {
			break;
		}
	}
}
