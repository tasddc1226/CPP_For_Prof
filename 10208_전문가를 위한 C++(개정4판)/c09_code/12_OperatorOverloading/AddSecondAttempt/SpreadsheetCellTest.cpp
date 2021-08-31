#include "SpreadsheetCell.h"

using namespace std;

int main()
{
	SpreadsheetCell myCell(4), anotherCell(5);
	SpreadsheetCell aThirdCell = myCell + anotherCell;
	//SpreadsheetCell aThirdCell = myCell.operator+(anotherCell);

	string str = "hello";

	aThirdCell = myCell + string_view(str);
	aThirdCell = myCell + 5.6;
	aThirdCell = myCell + 4;

	// 다음 두 문장에서 컴파일 에러가 발생한다.
	// aThirdCell = 4 + myCell; // 컴파일 에러!
	// aThirdCell = 5.6 + myCell; // 컴파일 에러!

	return 0;
}
