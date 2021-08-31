#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	SpreadsheetCell* cellPtr1 = new SpreadsheetCell(5);
	SpreadsheetCell* cellPtr2 = new SpreadsheetCell(6);

	cout << "cellPtr1: " << cellPtr1->getValue() << endl;

	delete cellPtr1; // cellPtr1을 제거한다.
	cellPtr1 = nullptr;

	return 0;
} // cellPtr2는 제거되지 않는다. 여기에 대해 delete를 호출하지 않았기 때문이다.
