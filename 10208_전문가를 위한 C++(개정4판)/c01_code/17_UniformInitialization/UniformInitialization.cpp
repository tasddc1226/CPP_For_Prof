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
	// C++11 이전 방식
	CircleStruct myCircle1 = {10, 10, 2.5};
	CircleClass myCircle2(10, 10, 2.5);

	// C++11 이후 방식
	CircleStruct myCircle3 = {10, 10, 2.5};
	CircleClass myCircle4 = {10, 10, 2.5};
	CircleStruct myCircle5{10, 10, 2.5};
	CircleClass myCircle6{10, 10, 2.5};

	int a = 3;
	int b(3);
	int c = { 3 }; // 유니폼 초기화
	int d{ 3 };    // 유니폼 초기화

	int e{};       // 유니폼 초기화, e는 0이 된다.

	// 암묵적 축소 변환 발생
	int x = 3.14;
	func(3.14);

	// 축소 변환되지 않는다.
	//int x = {3.14};    // 축소 변환 때문에 에러 발생
	//func({3.14});      // 축소 변환 때문에 에러 발생

	// 벡터에도 유니폼 초기화를 적용할 수 있다.
	vector<string> myVec = {"String 1", "String 2", "String 3"};

	// 동적으로 할당된 배열에도 유니폼 초기화를 적용할 수 있다.
	int* pArray = new int[4]{0, 1, 2, 3};
	delete[] pArray;
	pArray = nullptr;

	// MyClass 객체 생성
	MyClass myClass;

	return 0;
}
