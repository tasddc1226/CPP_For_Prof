#include <vector>
#include <string>

using namespace std;

struct CircleStruct
{
	int x, y;
	double radius;
};

class CircleClass
{
public:
	CircleClass(int x, int y, double radius)
		: mX(x), mY(y), mRadius(radius) {}
private:
	int mX, mY;
	double mRadius;
};

void func(int i) { /* ... */ }

class MyClass
{
public:
	MyClass() : mArray{0, 1, 2, 3} {}
private:
	int mArray[4];
};

int main()
{
	// C++11 ���� ���
	CircleStruct myCircle1 = {10, 10, 2.5};
	CircleClass myCircle2(10, 10, 2.5);

	// C++11 ���� ���
	CircleStruct myCircle3 = {10, 10, 2.5};
	CircleClass myCircle4 = {10, 10, 2.5};
	CircleStruct myCircle5{10, 10, 2.5};
	CircleClass myCircle6{10, 10, 2.5};

	int a = 3;
	int b(3);
	int c = { 3 }; // ������ �ʱ�ȭ
	int d{ 3 };    // ������ �ʱ�ȭ

	int e{};       // ������ �ʱ�ȭ, e�� 0�� �ȴ�.

	// �Ϲ��� ��� ��ȯ �߻�
	int x = 3.14;
	func(3.14);

	// ��� ��ȯ���� �ʴ´�.
	//int x = {3.14};    // ��� ��ȯ ������ ���� �߻�
	//func({3.14});      // ��� ��ȯ ������ ���� �߻�

	// ���Ϳ��� ������ �ʱ�ȭ�� ������ �� �ִ�.
	vector<string> myVec = {"String 1", "String 2", "String 3"};

	// �������� �Ҵ�� �迭���� ������ �ʱ�ȭ�� ������ �� �ִ�.
	int* pArray = new int[4]{0, 1, 2, 3};
	delete[] pArray;
	pArray = nullptr;

	// MyClass ��ü ����
	MyClass myClass;

	return 0;
}
