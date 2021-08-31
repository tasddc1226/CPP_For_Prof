#include "Logger.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
	// 로그 수준을 디버그(Debug)로 설정한다.
	Logger::instance().setLogLevel(Logger::LogLevel::Debug);

	// 로그 메시지를 남긴다.
	Logger::instance().log("test message", Logger::LogLevel::Debug);
	vector<string> items = {"item1", "item2"};
	Logger::instance().log(items, Logger::LogLevel::Error);

	// 로그 수준을 에러(Error)로 설정한다.
	Logger::instance().setLogLevel(Logger::LogLevel::Error);
	// 여기서부터는 로그 수준이 Error이므로 Debug 수준으로 지정된 메시지는 무시한다.
	Logger::instance().log("A debug message", Logger::LogLevel::Debug);

	return 0;
}
