#include "Logger.h"
#include <fstream>
#include <iostream>

using namespace std;

Logger::Logger()
{
	// ��׶��� �����带 �����Ѵ�.
	mThread = thread{ &Logger::processEntries, this };
}

void Logger::log(string_view entry)
{
	// ���ؽ��� ���� �ɰ� ť�� �׸��� �߰��Ѵ�.
	//unique_lock lock(mMutex);  // C++17
	unique_lock<mutex> lock(mMutex);
	mQueue.push(string(entry));

	// �����带 ����� ���� ������ �˸��� ������.
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

	// ť�� ó���ϴ� ������ �����Ѵ�.
	//unique_lock lock(mMutex);  // C++17
	unique_lock<mutex> lock(mMutex);
	while (true) {
		// �˸��� ���⸦ ��ٸ���.
		mCondVar.wait(lock);

		// ť�� ���� ��ȭ�� �־ ���� ������ �˸��� ������ ���
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
	}
}
