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
	// ... ���� �����ϴ� �ڵ带 ���⿡ �ۼ��Ѵ�. ����Ʈ �����ʹ� ������ ������ �ʿ䰡 ����.

	// ����Ʈ ������ ��� �Ϲ� �����͸� ����� ���� ������ �������� �ʴ´�.
	SpreadsheetCell* myCellp = new SpreadsheetCell(5);
	SpreadsheetCell* anotherCellp = nullptr;
	anotherCellp = new SpreadsheetCell(4);
	// ... do something with the cells
	delete myCellp; 		myCellp = nullptr;
	delete anotherCellp; 	anotherCellp = nullptr;

	SpreadsheetCell aThirdCell("test");  // string Ÿ�� �μ��� �޴� ctor
	SpreadsheetCell aFourthCell(4.4);    // double Ÿ�� �μ��� �޴� ctor
	auto aFifthCellp = make_unique<SpreadsheetCell>("5.5"); // string Ÿ�� �μ��� �޴� ctor
	cout << "aThirdCell: " << aThirdCell.getValue() << endl;
	cout << "aFourthCell: " << aFourthCell.getValue() << endl;
	cout << "aFifthCellp: " << aFifthCellp->getValue() << endl;

	return 0;
}
