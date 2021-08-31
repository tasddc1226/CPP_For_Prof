#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <string_view>

// �̱��� Logger Ŭ���� ����
class Logger final
{
public:
	enum class LogLevel {
		Error,
		Info,
		Debug
	};

	// �̱��� Logger ��ü�� ���� ���۷����� �����Ѵ�.
	static Logger& instance();

	// ����/�̵� ������ ���´�.
	Logger(const Logger&) = delete;
	Logger(Logger&&) = delete;

	// ����/�̵� ���� ������ ���´�.
	Logger& operator=(const Logger&) = delete;
	Logger& operator=(Logger&&) = delete;

	// �α� ������ �����Ѵ�.
	void setLogLevel(LogLevel level);

	// ��Ʈ������ ǥ���� �޽��� �ϳ��� ������ �α� �������� �α׿� �����.
	void log(std::string_view message, LogLevel logLevel);

	// ���Ϳ� ��� ���� �޽����� ������ �α� �������� �α׿� �����.
	void log(const std::vector<std::string>& messages,
		LogLevel logLevel);

private:
	// private �����ڿ� �Ҹ���
	Logger();
	~Logger();

	// �α� ������ ����� ���� �� �ִ� ��Ʈ�� ���·� ��ȯ�Ѵ�.
	std::string_view getLogLevelString(LogLevel level) const;

	static const char* const kLogFileName;
	std::ofstream mOutputStream;
	LogLevel mLogLevel = LogLevel::Error;
};
