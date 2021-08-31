#include "GridString.h"
#include <iostream>

using namespace std;

int main()
{
	Grid<int, 2, 2> myIntGrid;				// 원본 그리드를 사용한다.
	Grid<const char*, 2, 2> myStringGrid;	// 부분 특수화 버전 그리드를 사용한다.
	//  Grid<2, 3> test;					// 타입을 지정하지 않았기 때문에 컴파일 에러가 발생한다.

	myStringGrid.at(1, 1) = "Hello";
	Grid<const char*, 2, 2> myStringGridCopy(myStringGrid);
	myStringGridCopy.at(1, 1) = "World.";

	cout << myStringGrid.at(1, 1).value_or("") << endl;
	cout << myStringGridCopy.at(1, 1).value_or("") << endl;

	return 0;
}
