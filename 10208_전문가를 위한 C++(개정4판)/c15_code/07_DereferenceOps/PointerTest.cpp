#include "Pointer.h"
#include "SpreadsheetCell.h"
#include <iostream>
using namespace std;

void testConst(const Pointer<int>& p)
{
	cout << *p;
	//  *p = 7;
}

void TestConstTwo(const Pointer<SpreadsheetCell>& /*p*/)
{
	//  p->set(5);
}

int main()
{
	Pointer<int> smartInt(new int);

	*smartInt = 5; // 스마트 포인터를 역참조한다.
	cout << *smartInt << endl;

	Pointer<SpreadsheetCell> smartCell(new SpreadsheetCell);

	smartCell->set(5); // smartCell을 역참조해서 set 메서드 멤버를 선택한다.
	cout << smartCell->getValue() << endl;

	return 0;
}
