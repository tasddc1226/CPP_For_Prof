#include "SpreadsheetCell.h"
#include <iostream>
#include <memory>

using namespace std;

int main()
{
	SpreadsheetCell myCell;
	myCell.setValue(6);
	cout << "cell 1: " << myCell.getValue() << endl;

	auto smartCellp = make_unique<SpreadsheetCell>();
	// �����ϴ� ����� �ƴ����� ������ ���� �ۼ��ص� �ȴ�.
	SpreadsheetCell* myCellp = new SpreadsheetCell();
	// �Ǵ� ������ ���� �ۼ��� ���� �ִ�.
	// SpreadsheetCell* myCellp = new SpreadsheetCell;
	// ... myCellp�� ����ϴ� �ڵ带 ���⿡ �ۼ��Ѵ�.
	delete myCellp;    myCellp = nullptr;

	return 0;
}
