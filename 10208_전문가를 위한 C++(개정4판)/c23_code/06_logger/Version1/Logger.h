#pragma once

#include <queue>
#include <string>
#include <string_view>
#include <thread>
#include <mutex>
#include <condition_variable>

class Logger
{
public:
	// 로그 항목을 파일에 저장하는 백그라운드 스레드를 구동한다.
	Logger();
	// 복제 생성자와 복제 대입 연산자를 삭제한다.
	Logger(const Logger& src) = delete;
	Logger& operator=(const Logger& rhs) = delete;
	// 로그 항목을 큐에 저장하는 함수
	void log(std::string_view entry);

private:
	// 백그라운드 스레드에서 실행할 함수
	void processEntries();
	// 큐 동기화에 사용할 뮤텍스와 조건 변수
	std::mutex mMutex;
	std::condition_variable mCondVar;
	std::queue<std::string> mQueue;
	// 백그라운드 스레드
	std::thread mThread;
};
