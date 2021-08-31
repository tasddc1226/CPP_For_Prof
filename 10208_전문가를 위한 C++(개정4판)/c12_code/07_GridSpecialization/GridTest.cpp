#include <iostream>
#include <string>
#include "GridString.h"

using namespace std;

int main()
{
	Grid<int> myIntGrid;					// 원본 Grid 템플릿을 사용한다.
	Grid<const char*> stringGrid1(2, 2);	// const char*에 대한 특수화 버전을 적용한다.

	const char* dummy = "dummy";
	stringGrid1.at(0, 0) = "hello";
	stringGrid1.at(0, 1) = dummy;
	stringGrid1.at(1, 0) = dummy;
	stringGrid1.at(1, 1) = "there";

	Grid<const char*> stringGrid2(stringGrid1);

	cout << stringGrid1.at(0, 1).value_or("") << endl;
	cout << stringGrid2.at(0, 1).value_or("") << endl;

	return 0;
}
