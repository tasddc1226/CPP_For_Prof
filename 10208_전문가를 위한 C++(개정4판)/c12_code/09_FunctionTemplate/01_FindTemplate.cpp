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
			return i; // ���� ã���� �ε����� �����Ѵ�.
		}
	}
	return NOT_FOUND; // ���� ã�� ���ϸ� NOT_FOUND�� �����Ѵ�.
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
	res = Find(myInt, intArray, sizeIntArray);        // Ÿ�� ���߷� Find<int>�� ȣ���Ѵ�.
	res = Find<int>(myInt, intArray, sizeIntArray);   // ��������� Find<int>�� ȣ���Ѵ�.
	res = Find(myInt, intArray);
	if (res != NOT_FOUND)
		cout << res << endl;
	else
		cout << "Not found" << endl;

	double myDouble = 5.6, doubleArray[] = { 1.2, 3.4, 5.7, 7.5 };
	const size_t sizeDoubleArray = std::size(doubleArray);

	res = Find(myDouble, doubleArray, sizeDoubleArray);         // Ÿ�� ���߷� Find<double>�� ȣ���Ѵ�.
	res = Find<double>(myDouble, doubleArray, sizeDoubleArray); // ��������� Find<double>�� ȣ���Ѵ�.
	if (res != NOT_FOUND)
		cout << res << endl;
	else
		cout << "Not found" << endl;

	//res = Find(myInt, doubleArray, sizeDoubleArray);        // �μ� Ÿ���� �ٸ��� ������ ������ ������ �߻��Ѵ�.
	res = Find<double>(myInt, doubleArray, sizeDoubleArray);  // myInt�� �ִ��� ��������� Find<double>�� ȣ���Ѵ�.

	SpreadsheetCell cell1(10), cellArray[] = { SpreadsheetCell(4), SpreadsheetCell(10) };
	const size_t sizeCellArray = std::size(cellArray);

	res = Find(cell1, cellArray, sizeCellArray);                  // Ÿ�� ���߷� Find<SpreadsheetCell>�� ȣ���Ѵ�.
	res = Find<SpreadsheetCell>(cell1, cellArray, sizeCellArray); // ��������� Find<SpreadsheetCell>�� ȣ���Ѵ�.

	return 0;
}
