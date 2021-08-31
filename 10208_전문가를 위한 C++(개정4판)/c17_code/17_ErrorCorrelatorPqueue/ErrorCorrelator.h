#pragma once

#include <ostream>
#include <string>
#include <string_view>
#include <queue>

// 에러의 우선순위와 에러에 대한 설명만 필드로 갖도록 간단히 정의한 Error 클래스
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

// 우선순위가 가장 높은 에러를 먼저 리턴하도록 간단히 구현한 ErrorCorrelator 클래스
class ErrorCorrelator final
{
public:
	// 상관관계가 있는 에러를 추가한다.
	void addError(const Error& error);

	// 다음번에 처리할 에러를 가져온다.
	Error getError();

private:
	std::priority_queue<Error> mErrors;
};
