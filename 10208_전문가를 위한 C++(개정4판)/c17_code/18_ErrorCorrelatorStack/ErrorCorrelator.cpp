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
	// �� �̻� ������ ���ٸ� �ͼ����� ������.
	if (mErrors.empty()) {
		throw out_of_range("No more errors.");
	}

	// �Ǿտ� �ִ� ���Ҹ� �����Ѵ�.
	Error top = mErrors.top();
	// �Ǿտ� �ִ� ���Ҹ� �����Ѵ�.
	mErrors.pop();
	// �����ص� �Ǿ� ���Ҹ� �����Ѵ�.
	return top;
}
