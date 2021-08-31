#include "Array.h"
#include <cstddef>
#include <iostream>

using namespace std;

void printArray(const Array<int>& arr)
{
	for (size_t i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << " "; // arr�� const ��ü�̹Ƿ� const operator[]�� ȣ���Ѵ�.
	}
	cout << endl;
}

int main()
{
	Array<int> myArray;
	for (size_t i = 0; i < 10; i++) {
		myArray[i] = 100;	// myArray�� const ��ü�� �ƴϹǷ� non-const operator[]�� ȣ���Ѵ�.
	}
	printArray(myArray);

	//Array<int> myArray;
	//for (size_t i = 0; i < 10; i++) {
	//	myArray.setElementAt(i, 100);
	//}
	//for (size_t i = 0; i < 10; i++) {
	//	cout << myArray.getElementAt(i) << " ";
	//}

	return 0;
}
