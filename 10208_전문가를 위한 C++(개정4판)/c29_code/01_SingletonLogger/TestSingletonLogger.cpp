#include "Logger.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
	// �α� ������ �����(Debug)�� �����Ѵ�.
	Logger::instance().setLogLevel(Logger::LogLevel::Debug);

	// �α� �޽����� �����.
	Logger::instance().log("test message", Logger::LogLevel::Debug);
	vector<string> items = {"item1", "item2"};
	Logger::instance().log(items, Logger::LogLevel::Error);

	// �α� ������ ����(Error)�� �����Ѵ�.
	Logger::instance().setLogLevel(Logger::LogLevel::Error);
	// ���⼭���ʹ� �α� ������ Error�̹Ƿ� Debug �������� ������ �޽����� �����Ѵ�.
	Logger::instance().log("A debug message", Logger::LogLevel::Debug);

	return 0;
}
