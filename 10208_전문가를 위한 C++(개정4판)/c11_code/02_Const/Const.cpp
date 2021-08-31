#include <cstdlib>

const double PI = 3.141592653589793238462;

void func(const int /*param*/)
{
	// param�� �ٲ� �� ����.
}

void constIntOne()
{
	const int* ip;
	ip = new int[10];
	//  ip[4] = 5; // ������ ����!
}

void constIntTwo()
{
	int const* ip;
	ip = new int[10];
	//  ip[4] = 5; // ������ ����!
}

void constPtrOne()
{
	int* const ip = nullptr;
	//  ip = new int[10]; // ������ ����!
	ip[4] = 5;	// ����: �� �����͸� �������Ѵ�.
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
	// ���� �ڵ带 ���� ���´�.
}

int main()
{
	int* ip;
	ip = new int[10];
	ip[4] = 5;

	int z;
	const int& zRef = z;
	//  zRef = 4; // ������ ����!

	return 0;
}
