#include "SpreadsheetCell.h"

int main()
{
	SpreadsheetCell myCell, anotherCell, aThirdCell;

	myCell = anotherCell = aThirdCell;
	myCell.operator=(anotherCell.operator=(aThirdCell));

	SpreadsheetCell cell(4);
	cell = cell; // 자기 자신을 대입한다.

	return 0;
}
