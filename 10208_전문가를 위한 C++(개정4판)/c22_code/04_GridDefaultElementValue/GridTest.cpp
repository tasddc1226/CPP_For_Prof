#include "Grid.h"
#include "SpreadsheetCell.h"

int main()
{
	Grid<int> myIntGrid;		// 초깃값은 0
	Grid<int, 10> myIntGrid2;	// 초깃값은 10

	myIntGrid.at(1, 2) = 3;

	SpreadsheetCell defaultCell;
	//Grid<SpreadsheetCell, defaultCell> mySpreadsheet; // 컴파일 에러 발생!

	return 0;
}
