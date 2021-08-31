#pragma once

#include <ostream>
#include <string>
#include <string_view>
#include <stack>

// ������ �켱������ ������ ���� ���� �ʵ�� ������ ������ ������ Error Ŭ����
class Error final
{
public:
	Error(int priority, std::string_view errorString) : mPriority(priority), mErrorString(errorString) {}
	int getPriority() const { return mPriority; }
	std::string_view getErrorString() const { return mErrorString; }

private:
	int mPriority;
	std::string mErrorString;
};

bool operator<(const Error& lhs, const Error& rhs);
std::ostream& operator<<(std::ostream& os, const Error& err);

// ���� �ֱ� �������� �����ϵ��� ������ ������ ErrorCorrelator Ŭ����
class ErrorCorrelator final
{
public:
	// ������谡 �ִ� ������ �߰��Ѵ�.
	void addError(const Error& error);

	// �������� ó���� ������ �����´�.
	Error getError();

private:
	std::stack<Error> mErrors;
};
