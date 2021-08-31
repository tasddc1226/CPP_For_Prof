#include "Logger.h"
#include <fstream>
#include <iostream>

using namespace std;

Logger::Logger()
{
	// 백그라운드 스레드를 구동한다.
	mThread = thread{ &Logger::processEntries, this };
}

void Logger::log(string_view entry)
{
	// 뮤텍스에 락을 걸고 큐에 항목을 추가한다.
	//unique_lock lock(mMutex);  // C++17
	unique_lock<mutex> lock(mMutex);
	mQueue.push(string(entry));

	// 스레드를 깨우는 조건 변수에 알림을 보낸다.
	mCondVar.notify_all();
}

void Logger::processEntries()
{
	// 로그 파일을 연다.
	ofstream logFile("log.txt");
	if (logFile.fail()) {
		cerr << "Failed to open logfile." << endl;
		return;
	}

	// 큐를 처리하는 루프를 시작한다.
	//unique_lock lock(mMutex);  // C++17
	unique_lock<mutex> lock(mMutex);
	while (true) {
		// 알림이 오기를 기다린다.
		mCondVar.wait(lock);

		// 큐에 뭔가 변화가 있어서 조건 변수에 알림이 도착할 경우
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
