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
	// 권장하는 방법은 아니지만 다음과 같이 작성해도 된다.
	SpreadsheetCell* myCellp = new SpreadsheetCell();
	// 또는 다음과 같이 작성할 수도 있다.
	// SpreadsheetCell* myCellp = new SpreadsheetCell;
	// ... myCellp을 사용하는 코드를 여기에 작성한다.
	delete myCellp;    myCellp = nullptr;

	return 0;
}
