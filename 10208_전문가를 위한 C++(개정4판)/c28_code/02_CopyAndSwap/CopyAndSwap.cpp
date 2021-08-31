#include "CopyAndSwap.h"
#include <utility>

CopyAndSwap::~CopyAndSwap()
{
	// 소멸자 구현 코드
}

CopyAndSwap::CopyAndSwap(const CopyAndSwap& src)
{
	// 이 복제 생성자는 먼저 필요한 리소스 할당 작업을 비복제 생성자에 위임한다.
	// 자세한 사항은 9장의 Spreadsheet 구현 코드를 참조한다.

	// 데이터 멤버를 모두 복제한다.
}

void swap(CopyAndSwap& first, CopyAndSwap& second) noexcept
{
	using std::swap;  // <utility>를 인클루드해야 한다.

	// 데이터 멤버를 모두 맞바꾼다. 예를 들어 다음과 같이 작성한다.
	// swap(first.mData, second.mData);
}

CopyAndSwap& CopyAndSwap::operator=(const CopyAndSwap& rhs)
{
	// 자기 자신 대입 여부 확인
	if (this == &rhs) {
		return *this;
	}

	auto copy(rhs);  // 모든 작업을 임시 인스턴스에서 처리한다.
	swap(*this, copy); // 익셉션을 던지지 않는 연산으로만 작업 결과를 반영한다.
	return *this;
}


int main()
{
	CopyAndSwap myFirstInstance;
	CopyAndSwap mySecondInstance;
	mySecondInstance = myFirstInstance;

	return 0;
}
