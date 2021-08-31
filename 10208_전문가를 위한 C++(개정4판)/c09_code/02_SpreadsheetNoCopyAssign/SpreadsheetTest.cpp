#include "Spreadsheet.h"

void printSpreadsheet(Spreadsheet s)
{
	// 코드 생략
}

int main()
{
	//Spreadsheet s1(4, 3);
	//printSpreadsheet(s1);

	Spreadsheet s1(2, 2), s2(4, 3);
	s1 = s2;

	return 0;
}
