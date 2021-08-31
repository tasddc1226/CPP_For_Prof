#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	// double d2 = cell + 3.3; // 명시적으로 double 변환 연산자를 선언하면 이 문장에서 컴파일 에러 발생함

	// double 변환 연산자를 명시적으로 선언한 예
	SpreadsheetCell cell = 6.6;
	string str = cell;
	double d1 = static_cast<double>(cell);
	double d2 = static_cast<double>(cell + 3.3);
	cout << str << endl;
	cout << d1 << endl;
	cout << d2 << endl;

	return 0;
}
