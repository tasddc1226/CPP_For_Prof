#include "ErrorCorrelator.h"
#include <stdexcept>

using namespace std;

bool operator<(const Error& lhs, const Error& rhs)
{
	return (lhs.getPriority() < rhs.getPriority());
}

ostream& operator<<(ostream& os, const Error& err)
{
	os << err.getErrorString() << " (priority " << err.getPriority() << ")";
	return os;
}

void ErrorCorrelator::addError(const Error& error)
{
	mErrors.push(error);
}

Error ErrorCorrelator::getError()
{
	// 더 이상 에러가 없다면 익셉션을 던진다.
	if (mErrors.empty()) {
		throw out_of_range("No more errors.");
	}

	// 맨앞에 있는 원소를 저장한다.
	Error top = mErrors.top();
	// 맨앞에 있는 원소를 제거한다.
	mErrors.pop();
	// 저장해둔 맨앞 원소를 리턴한다.
	return top;
}
