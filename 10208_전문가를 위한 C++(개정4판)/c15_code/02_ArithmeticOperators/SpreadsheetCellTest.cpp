#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	int i, j = 4;
	i = -j; // ���� ���� ������
	i = +i; // ���� ���� ������
	j = +(-i); // i�� ���� ���� ���� ������ ����� ���� ���� �����ڸ� �����Ѵ�.
	j = -(-i); // i�� ���� ���� ���� ������ ����� ���� ���� �����ڸ� �����Ѵ�.

	i = i + 1;
	i += 1;
	++i;
	i++;

	SpreadsheetCell c1(4);
	SpreadsheetCell c2(4);
	SpreadsheetCell c3 = -c1;
	c1++;
	++c2;

	return 0;
}
