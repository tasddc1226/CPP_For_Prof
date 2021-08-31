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
	// �α� �׸��� ���Ͽ� �����ϴ� ��׶��� �����带 �����Ѵ�.
	Logger();
	// ���� �����ڿ� ���� ���� �����ڸ� �����Ѵ�.
	Logger(const Logger& src) = delete;
	Logger& operator=(const Logger& rhs) = delete;
	// �α� �׸��� ť�� �����ϴ� �Լ�
	void log(std::string_view entry);

private:
	// ��׶��� �����忡�� ������ �Լ�
	void processEntries();
	// ť ����ȭ�� ����� ���ؽ��� ���� ����
	std::mutex mMutex;
	std::condition_variable mCondVar;
	std::queue<std::string> mQueue;
	// ��׶��� ������
	std::thread mThread;
};
