#include <cstdlib>
#include <iostream>
using namespace std;

void memoryLeak()
{
	int* p = new int[1000];
	return; // 버그! p를 해제하지 않았다.
}

void mismatchedFree()
{
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;
	int* p3 = new int[1000];
	delete p1;    // 버그! free()를 사용해야 한다.
	delete [] p2; // 버그! delete를 사용해야 한다.
	free(p3);     // 버그! delete []를 사용해야 한다.
}

void doubleFree()
{
	int* p1 = new int[1000];
	delete [] p1;
	int* p2 = new int[1000];
	delete [] p1; // 버그! p1을 두 번 해제했다.
} // 버그! p2의 메모리에 누수가 발생한다.

void freeUnallocated()
{
	int* p = reinterpret_cast<int*>(10000);
	delete p; // 버그! p는 올바른 포인터가 아니다.
}

void freeStack()
{
	int x;
	int* p = &x;
	delete p; // 버그! 스택 메모리 해제
}

void accessInvalid()
{
	int* p = reinterpret_cast<int*>(10000);
	*p = 5;    // 버그! p는 잘못된 포인터다.
}

void accessFreed()
{
	int* p1 = new int;
	delete p1;
	int* p2 = new int;
	*p1 = 5; // 버그!. p1이 가리키는 메모리는 이미 해제됐다.
}

void accessElsewhere()
{
	int x, y[10], z;
	x = 0;
	z = 0;
	for (int i = 0; i <= 10; i++) {
		y[i] = 5; // 버그! i==10일때 y의 원소는 배열의 경계를 벗어난다.
	}
}

void readUninitialized()
{
	int* p;
	cout << *p << endl; // 버그! p를 초기화하지 않았다.
}

int main()
{
	cout << "Memory leak" << endl;
	memoryLeak();
	cout << "Mismatched Free" << endl;
	mismatchedFree();
	cout << "Double Free" << endl;
	doubleFree();
	cout << "Free Unallocated" << endl;
	freeUnallocated();
	cout << "Free Stack" << endl;
	freeStack();
	cout << "Access Invalid" << endl;
	accessInvalid();
	cout << "Access Freed" << endl;
	accessFreed();
	cout << "Access Elsewhere" << endl;
	accessElsewhere();
	cout << "Read Uninitialized" << endl;
	readUninitialized();

	return 0;
}
