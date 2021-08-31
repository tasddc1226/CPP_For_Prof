#include "SpreadsheetCell.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
	SpreadsheetCell myCell(4), anotherCell(5);
	SpreadsheetCell aThirdCell = myCell + anotherCell;

	// 다음 두 문장은 명시적 스트링 ctor를 적용할 수 없다.
	// string str = "hello";
	// aThirdCell = myCell + str;

	aThirdCell = myCell + 5.6;
	aThirdCell = myCell + 4;

	aThirdCell = 4 + myCell;   // 문제 없이 실행된다.
	aThirdCell = 5.6 + myCell; // 문제 없이 실행된다.
	aThirdCell = 4.5 + 5.5;

	aThirdCell = myCell - anotherCell;
	aThirdCell = myCell * anotherCell;
	aThirdCell = myCell / anotherCell;

	try {
		aThirdCell = myCell / 0;
	} catch (const invalid_argument& e) {
		cout << "Caught: " << e.what() << endl;
	}

	aThirdCell -= myCell;
	aThirdCell += 5.4;
	aThirdCell *= myCell;
	aThirdCell /= myCell;

	if (myCell > aThirdCell || myCell < 10) {
		cout << myCell.getValue() << endl;
	}

	if (anotherCell == myCell) {
		cout << "cells are equal\n";
	} else {
		cout << "cells are not equal\n";
	}

	return 0;
}
