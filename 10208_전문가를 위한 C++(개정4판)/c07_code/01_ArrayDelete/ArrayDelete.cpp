#include <cstddef>
#include <iostream>

using namespace std;

class Simple
{
public:
	Simple() { cout << "Simple constructor called!" << endl; }
	~Simple() { cout << "Simple destructor called!" << endl; }
};

int main()
{
	Simple* mySimpleArray = new Simple[4];
	//  mySimpleArray를 사용하는 코드를 여기에 작성한다.
	delete[] mySimpleArray;
	mySimpleArray = nullptr;


	const size_t size = 4;
	Simple** mySimplePtrArray = new Simple*[size];

	// 각 포인터마다 객체를 할당한다.
	for (size_t i = 0; i < size; i++) { mySimplePtrArray[i] = new Simple(); }

	// mySimplePtrArray를 사용하는 코드를 여기에 작성한다.

	// 할당했던 객체들을 삭제한다.
	for (size_t i = 0; i < size; i++) { delete mySimplePtrArray[i]; }

	// 배열도 삭제한다.
	delete[] mySimplePtrArray;
	mySimplePtrArray = nullptr;

	return 0;
}
