#include "SpreadsheetCell.h"
#include <iostream>
#include <memory>

using namespace std;

int main()
{
	SpreadsheetCell myCell(5), anotherCell(4);
	cout << "cell 1: " << myCell.getValue() << endl;
	cout << "cell 2: " << anotherCell.getValue() << endl;

	auto smartCellp = make_unique<SpreadsheetCell>(4);
	// ... 셀을 조작하는 코드를 여기에 작성한다. 스마트 포인터는 별도로 삭제할 필요가 없다.

	// 스마트 포인터 대신 일반 포인터를 사용할 수도 있지만 권장하지 않는다.
	SpreadsheetCell* myCellp = new SpreadsheetCell(5);
	SpreadsheetCell* anotherCellp = nullptr;
	anotherCellp = new SpreadsheetCell(4);
	// ... do something with the cells
	delete myCellp; 		myCellp = nullptr;
	delete anotherCellp; 	anotherCellp = nullptr;

	SpreadsheetCell aThirdCell("test");  // string 타입 인수를 받는 ctor
	SpreadsheetCell aFourthCell(4.4);    // double 타입 인수를 받는 ctor
	auto aFifthCellp = make_unique<SpreadsheetCell>("5.5"); // string 타입 인수를 받는 ctor
	cout << "aThirdCell: " << aThirdCell.getValue() << endl;
	cout << "aFourthCell: " << aFourthCell.getValue() << endl;
	cout << "aFifthCellp: " << aFifthCellp->getValue() << endl;

	return 0;
}
