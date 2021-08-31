#include "Logger.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

using namespace std;

void logSomeMessages(int id, Logger& logger)
{
	for (int i = 0; i < 10; ++i) {
		stringstream ss;
		ss << "Log entry " << i << " from thread " << id;
		logger.log(ss.str());
	}
}

int main()
{
	Logger logger;

	vector<thread> threads;
	// 동일한 Logger 인스턴스를 사용하는 스레드를 여러 개 생성한다.
	for (int i = 0; i < 10; ++i) {
		threads.emplace_back(logSomeMessages, i, ref(logger));
		// 위 문장 대신 다음과 같이 작성해도 된다.
		// threads.push_back(thread{ logSomeMessages, i, ref(logger) });
	}

	// 모든 스레드가 끝날 때까지 기다린다.
	for (auto& t : threads) {
		t.join();
	}

	return 0;
}
