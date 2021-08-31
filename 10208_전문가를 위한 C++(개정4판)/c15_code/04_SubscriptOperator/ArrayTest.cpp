#include "Array.h"
#include <cstddef>
#include <iostream>

using namespace std;

void printArray(const Array<int>& arr)
{
	for (size_t i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << " "; // arr이 const 객체이므로 const operator[]를 호출한다.
	}
	cout << endl;
}

int main()
{
	Array<int> myArray;
	for (size_t i = 0; i < 10; i++) {
		myArray[i] = 100;	// myArray는 const 객체가 아니므로 non-const operator[]를 호출한다.
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
