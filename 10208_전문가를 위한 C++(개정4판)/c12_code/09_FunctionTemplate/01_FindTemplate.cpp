#include <cstddef>
#include <iostream>
#include <array>
#include "SpreadsheetCell.h"

using namespace std;

static const size_t NOT_FOUND = static_cast<size_t>(-1);

template <typename T>
size_t Find(const T& value, const T* arr, size_t size)
{
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			return i; // 값을 찾으면 인덱스를 리턴한다.
		}
	}
	return NOT_FOUND; // 값을 찾지 못하면 NOT_FOUND를 리턴한다.
}

template <typename T, size_t N>
size_t Find(const T& value, const T(&arr)[N])
{
	return Find(value, arr, N);
}

int main()
{
	int myInt = 3, intArray[] = { 1, 2, 3, 4 };
	const size_t sizeIntArray = std::size(intArray);

	size_t res;
	res = Find(myInt, intArray, sizeIntArray);        // 타입 유추로 Find<int>를 호출한다.
	res = Find<int>(myInt, intArray, sizeIntArray);   // 명시적으로 Find<int>를 호출한다.
	res = Find(myInt, intArray);
	if (res != NOT_FOUND)
		cout << res << endl;
	else
		cout << "Not found" << endl;

	double myDouble = 5.6, doubleArray[] = { 1.2, 3.4, 5.7, 7.5 };
	const size_t sizeDoubleArray = std::size(doubleArray);

	res = Find(myDouble, doubleArray, sizeDoubleArray);         // 타입 유추로 Find<double>를 호출한다.
	res = Find<double>(myDouble, doubleArray, sizeDoubleArray); // 명시적으로 Find<double>를 호출한다.
	if (res != NOT_FOUND)
		cout << res << endl;
	else
		cout << "Not found" << endl;

	//res = Find(myInt, doubleArray, sizeDoubleArray);        // 인수 타입이 다르기 때문에 컴파일 에러가 발생한다.
	res = Find<double>(myInt, doubleArray, sizeDoubleArray);  // myInt가 있더라도 명시적으로 Find<double>를 호출한다.

	SpreadsheetCell cell1(10), cellArray[] = { SpreadsheetCell(4), SpreadsheetCell(10) };
	const size_t sizeCellArray = std::size(cellArray);

	res = Find(cell1, cellArray, sizeCellArray);                  // 타입 유추로 Find<SpreadsheetCell>를 호출한다.
	res = Find<SpreadsheetCell>(cell1, cellArray, sizeCellArray); // 명시적으로 Find<SpreadsheetCell>를 호출한다.

	return 0;
}
