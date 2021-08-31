#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	int i, j = 4;
	i = -j; // 단항 뺄셈 연산자
	i = +i; // 단항 덧셈 연산자
	j = +(-i); // i에 대한 단항 뺄셈 연산의 결과에 단항 덧셈 연산자를 적용한다.
	j = -(-i); // i에 대한 단항 뺄셈 연산의 결과에 단항 뺄셈 연산자를 적용한다.

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
