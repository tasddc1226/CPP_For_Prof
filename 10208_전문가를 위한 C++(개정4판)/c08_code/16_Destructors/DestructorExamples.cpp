#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	SpreadsheetCell myCell(5);

	if (myCell.getValue() == 5) {
		SpreadsheetCell anotherCell(6);
	} // �� ����� ����� anotherCell�� ���ŵȴ�.

	cout << "myCell: " << myCell.getValue() << endl;

	{
		SpreadsheetCell myCell2(4);
		SpreadsheetCell anotherCell2(5); // myCell2�� anotherCell2���� ���� �����ȴ�.
	} // anotherCell2�� myCell2���� ���� ���ŵȴ�.

	return 0;
} // �� ����� ����� myCell�� ���ŵȴ�.
