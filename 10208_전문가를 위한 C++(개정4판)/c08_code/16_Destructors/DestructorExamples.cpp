#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	SpreadsheetCell myCell(5);

	if (myCell.getValue() == 5) {
		SpreadsheetCell anotherCell(6);
	} // 이 블록을 벗어나면 anotherCell은 제거된다.

	cout << "myCell: " << myCell.getValue() << endl;

	{
		SpreadsheetCell myCell2(4);
		SpreadsheetCell anotherCell2(5); // myCell2은 anotherCell2보다 먼저 생성된다.
	} // anotherCell2은 myCell2보다 먼저 제거된다.

	return 0;
} // 이 블록을 벗어나면 myCell이 제거된다.
