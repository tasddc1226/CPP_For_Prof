#include <cstddef>
#include <iostream>
#include <cstring>
#include <array>
#include "SpreadsheetCell.h"

using namespace std;

static const size_t NOT_FOUND = static_cast<size_t>(-1);

template <typename T>
size_t Find(const T& value, const T* arr, size_t size)
{
	cout << "original" << endl;
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			return i; // ã�Ҵ�! �ε����� �����Ѵ�.
		}
	}
	return NOT_FOUND; // �� ã�Ҵ�. NOT_FOUND�� �����Ѵ�.
}

template <typename T>
size_t Find(T* const& value, T* const* arr, size_t size)
{
	cout << "ptr special" << endl;
	for (size_t i = 0; i < size; i++) {
		if (*arr[i] == *value) {
			return i; // ã�Ҵ�. �ε����� �����Ѵ�.
		}
	}
	return NOT_FOUND; // �� ã�Ҵ�. NOT_FOUND�� �����Ѵ�.
}

/* // �� �ڵ�� �߸� �ƴ�.
template <typename T>
size_t Find<T*>(T* const& value, T* const* arr, size_t size)
{
	cout << "ptr special" << endl;
	for (size_t i = 0; i < size; i++) {
		if (*arr[i] == *value) {
			return i; // ã�Ҵ�. �ε����� �����Ѵ�.
		}
	}
	return NOT_FOUND; // �� ã�Ҵ�. NOT_FOUND�� �����Ѵ�.
}
*/

template<>
size_t Find<const char*>(const char* const& value, const char* const* arr, size_t size)
{
	cout << "Specialization" << endl;
	for (size_t i = 0; i < size; i++) {
		if (strcmp(arr[i], value) == 0) {
			return i; // ã�Ҵ�. �ε����� �����Ѵ�.
		}
	}
	return NOT_FOUND; // �� ã�Ҵ�. NOT_FOUND�� �����Ѵ�.
}

size_t Find(const char* const& value, const char* const* arr, size_t size)
{
	cout << "overload" << endl;
	for (size_t i = 0; i < size; i++) {
		if (strcmp(arr[i], value) == 0) {
			return i; // ã�Ҵ�. �ε����� �����Ѵ�.
		}
	}
	return NOT_FOUND; // �� ã�Ҵ�. NOT_FOUND�� �����Ѵ�.
}

int main()
{
	size_t res = NOT_FOUND;

	int myInt = 3, intArray[] = { 1, 2, 3, 4 };
	size_t sizeArray = std::size(intArray);
	res = Find(myInt, intArray, sizeArray);      // �߷п� ���� Find<int>�� ȣ���Ѵ�.
	res = Find<int>(myInt, intArray, sizeArray); // ��������� Find<int>�� ȣ���Ѵ�.

	double myDouble = 5.6, doubleArray[] = { 1.2, 3.4, 5.7, 7.5 };
	sizeArray = std::size(doubleArray);
	res = Find(myDouble, doubleArray, sizeArray);         // �߷п� ���� Find<double>�� ȣ���Ѵ�.
	res = Find<double>(myDouble, doubleArray, sizeArray); // ��������� Find<double>�� ȣ���Ѵ�.

	const char* word = "two";
	const char* words[] = { "one", "two", "three", "four" };
	sizeArray = std::size(words);
	res = Find<const char*>(word, words, sizeArray);  // const char*s�� ���� ���ø� Ư��ȭ ������ ȣ���Ѵ�.
	res = Find(word, words, sizeArray);		          // const char*s�� ���� �����ε� �� ������ ȣ���Ѵ�.

	int *intPointer = &myInt, *pointerArray[] = { &myInt, &myInt };
	sizeArray = std::size(pointerArray);
	res = Find(intPointer, pointerArray, sizeArray);    // �����Ϳ� ���� �����ε��� ������ ȣ���Ѵ�.

	SpreadsheetCell cell1(10), cellArray[] = { SpreadsheetCell(4), SpreadsheetCell(10) };
	sizeArray = std::size(cellArray);
	res = Find(cell1, cellArray, sizeArray);                  // �߷п� ���� Find<SpreadsheetCell>�� ȣ���Ѵ�.
	res = Find<SpreadsheetCell>(cell1, cellArray, sizeArray); // ��������� Find<SpreadsheetCell>�� ȣ���Ѵ�.

	SpreadsheetCell *cellPointer = &cell1;
	SpreadsheetCell *cellPointerArray[] = { &cell1, &cell1 };
	sizeArray = std::size(cellPointerArray);
	res = Find(cellPointer, cellPointerArray, sizeArray); // �����Ϳ� ���� �����ε� �� ������ ȣ���Ѵ�.

	return 0;
}
