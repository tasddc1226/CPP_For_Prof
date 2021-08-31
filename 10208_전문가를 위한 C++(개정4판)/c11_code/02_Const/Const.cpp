#include <cstdlib>

const double PI = 3.141592653589793238462;

void func(const int /*param*/)
{
	// param을 바꿀 수 없다.
}

void constIntOne()
{
	const int* ip;
	ip = new int[10];
	//  ip[4] = 5; // 컴파일 에러!
}

void constIntTwo()
{
	int const* ip;
	ip = new int[10];
	//  ip[4] = 5; // 컴파일 에러!
}

void constPtrOne()
{
	int* const ip = nullptr;
	//  ip = new int[10]; // 컴파일 에러!
	ip[4] = 5;	// 에러: 널 포인터를 역참조한다.
}

void constPtrTwo()
{
	int* const ip = new int[10];
	ip[4] = 5;
}

void constIntPtrOne()
{
	int const* const ip = nullptr;
}

void constIntPtrTwo()
{
	const int* const ip = nullptr;
}

void manyLevelConst()
{
	const int * const * const * const ip = nullptr;
}

class BigClass;
void doSomething(const BigClass& /*arg*/)
{
	// 구현 코드를 여기 적는다.
}

int main()
{
	int* ip;
	ip = new int[10];
	ip[4] = 5;

	int z;
	const int& zRef = z;
	//  zRef = 4; // 컴파일 에러!

	return 0;
}
