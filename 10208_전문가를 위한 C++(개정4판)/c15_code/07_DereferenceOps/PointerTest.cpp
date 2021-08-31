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

	*smartInt = 5; // ����Ʈ �����͸� �������Ѵ�.
	cout << *smartInt << endl;

	Pointer<SpreadsheetCell> smartCell(new SpreadsheetCell);

	smartCell->set(5); // smartCell�� �������ؼ� set �޼��� ����� �����Ѵ�.
	cout << smartCell->getValue() << endl;

	return 0;
}
