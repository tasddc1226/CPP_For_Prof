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
	virtual ~Logger() = default;  // �׻� ���� �Ҹ��ڷ� �����Ѵ�.

	void log(LogLevel level, std::string message);

private:
	// �α� ������ ����� ���� �� �ִ� ��Ʈ�� �������� ��ȯ�Ѵ�.
	std::string_view getLogLevelString(LogLevel level) const;
};

class NewLoggerInterface
{
public:
	virtual ~NewLoggerInterface() = default;  // �׻� ���� �Ҹ��ڷ� �����Ѵ�.
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
