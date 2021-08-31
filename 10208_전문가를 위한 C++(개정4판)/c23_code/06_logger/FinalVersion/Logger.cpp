#include "Logger.h"
#include <fstream>
#include <iostream>
#include <chrono>

using namespace std;

Logger::Logger()
{
	// 백그라운드 스레드를 구동한다.
	mThread = thread{ &Logger::processEntries, this };
}

Logger::~Logger()
{
	{
		//unique_lock lock(mMutex);  // C++17
		unique_lock<mutex> lock(mMutex);
		// mExit를 true로 설정하고 스레드에 알림을 보내서 스레드를 정상 종료시킨다.
		mExit = true;
		// 조건 변수에 알림을 보내서 스레드를 깨운다.
		mCondVar.notify_all();
	}
	// 스레드가 종료될 때까지 기다린다. 이 부분은 앞에 나온 블록 밖에 둬야 한다.
	// join()을 호출하기 전에 반드시 락을 해제해야 하기 때문이다.
	mThread.join();
}

void Logger::log(string_view entry)
{
	// 뮤텍스에 락을 걸고 큐에 로그 항목을 추가한다.
	//unique_lock lock(mMutex);  // C++17
	unique_lock<mutex> lock(mMutex);
	mQueue.push(string(entry));

	// 조건 변수에 알림을 보내 스레드를 깨운다.
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

	// 큐 처리 반복문 시작
	//unique_lock lock(mMutex);  // C++17
	unique_lock<mutex> lock(mMutex);
	while (true) {
		
		// 특정한 동작을 발생시키기 위해 멀티스레드로 실행되는 코드의 일정 부분을 실행 지연시킬 수 있다.
		// 단, 이런 지연 코드는 테스트 용도로만 사용하고, 최종 버전에서는 삭제한다.
		//
		// 예를 들어 Logger 클래스의 소멸자에서 발생하던 데이터 경쟁이 
		// 23장에서 설명한 방식대로 완전히 해결됐는지 확인하도록 다음과 같이 작성할 수 있다.
		//this_thread::sleep_for(1000ms); // Needs #include <chrono>

		if (!mExit) { // 종료할 필요가 없을 때만 알림을 기다린다.
			// 알림을 기다린다.
			mCondVar.wait(lock);
		}

		// 큐에 항목이 추가되거나 스레드를 종료시킬 상황이 발생하면 조건 변수에 알림이 전달된다.
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
