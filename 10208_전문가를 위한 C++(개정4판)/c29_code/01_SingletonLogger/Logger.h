#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <string_view>

// 싱글턴 Logger 클래스 정의
class Logger final
{
public:
	enum class LogLevel {
		Error,
		Info,
		Debug
	};

	// 싱글턴 Logger 객체에 대한 레퍼런스를 리턴한다.
	static Logger& instance();

	// 복제/이동 생성을 막는다.
	Logger(const Logger&) = delete;
	Logger(Logger&&) = delete;

	// 복제/이동 대입 연산을 막는다.
	Logger& operator=(const Logger&) = delete;
	Logger& operator=(Logger&&) = delete;

	// 로그 수준을 설정한다.
	void setLogLevel(LogLevel level);

	// 스트링으로 표현한 메시지 하나를 지정된 로그 수준으로 로그에 남긴다.
	void log(std::string_view message, LogLevel logLevel);

	// 벡터에 담긴 여러 메시지를 지정된 로그 수준으로 로그에 남긴다.
	void log(const std::vector<std::string>& messages,
		LogLevel logLevel);

private:
	// private 생성자와 소멸자
	Logger();
	~Logger();

	// 로그 수준을 사람이 읽을 수 있는 스트링 형태로 변환한다.
	std::string_view getLogLevelString(LogLevel level) const;

	static const char* const kLogFileName;
	std::ofstream mOutputStream;
	LogLevel mLogLevel = LogLevel::Error;
};
