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
	//  mySimpleArray�� ����ϴ� �ڵ带 ���⿡ �ۼ��Ѵ�.
	delete[] mySimpleArray;
	mySimpleArray = nullptr;


	const size_t size = 4;
	Simple** mySimplePtrArray = new Simple*[size];

	// �� �����͸��� ��ü�� �Ҵ��Ѵ�.
	for (size_t i = 0; i < size; i++) { mySimplePtrArray[i] = new Simple(); }

	// mySimplePtrArray�� ����ϴ� �ڵ带 ���⿡ �ۼ��Ѵ�.

	// �Ҵ��ߴ� ��ü���� �����Ѵ�.
	for (size_t i = 0; i < size; i++) { delete mySimplePtrArray[i]; }

	// �迭�� �����Ѵ�.
	delete[] mySimplePtrArray;
	mySimplePtrArray = nullptr;

	return 0;
}
