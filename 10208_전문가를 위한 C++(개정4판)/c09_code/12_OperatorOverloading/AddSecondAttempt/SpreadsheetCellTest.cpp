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

	// ���� �� ���忡�� ������ ������ �߻��Ѵ�.
	// aThirdCell = 4 + myCell; // ������ ����!
	// aThirdCell = 5.6 + myCell; // ������ ����!

	return 0;
}
