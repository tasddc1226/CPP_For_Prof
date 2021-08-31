#pragma once

#include <string>
#include <string_view>

class Logger
{
public:
	enum class LogLevel {
		Error,
		Info,
		Debug
	};

	Logger();
	virtual ~Logger() = default;  // 항상 가상 소멸자로 정의한다.

	void log(LogLevel level, std::string message);

private:
	// 로그 수준을 사람이 읽을 수 있는 스트링 포맷으로 변환한다.
	std::string_view getLogLevelString(LogLevel level) const;
};

class NewLoggerInterface
{
public:
	virtual ~NewLoggerInterface() = default;  // 항상 가상 소멸자로 정의한다.
	virtual void log(std::string_view message) = 0;
};

class NewLoggerAdaptor : public NewLoggerInterface
{
public:
	NewLoggerAdaptor();
	virtual void log(std::string_view message) override;

private:
	Logger mLogger;
};
