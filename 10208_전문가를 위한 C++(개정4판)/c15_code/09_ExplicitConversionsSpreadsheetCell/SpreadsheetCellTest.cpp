#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	// double d2 = cell + 3.3; // ��������� double ��ȯ �����ڸ� �����ϸ� �� ���忡�� ������ ���� �߻���

	// double ��ȯ �����ڸ� ��������� ������ ��
	SpreadsheetCell cell = 6.6;
	string str = cell;
	double d1 = static_cast<double>(cell);
	double d2 = static_cast<double>(cell + 3.3);
	cout << str << endl;
	cout << d1 << endl;
	cout << d2 << endl;

	return 0;
}
