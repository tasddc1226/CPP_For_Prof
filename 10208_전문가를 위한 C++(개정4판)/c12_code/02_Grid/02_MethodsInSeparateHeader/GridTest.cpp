#include "Grid.h"
#include "SpreadsheetCell.h"
#include <vector>
#include <memory>

using namespace std;

void processIntGrid(Grid<int>& /*grid*/)
{
	// 코드 생략
}

int main()
{
	Grid<int> myIntGrid; // int 값을 저장할 Grid 객체를 선언한다.
                         // 이때 생성자에 디폴트 인수를 적용한다.
	Grid<double> myDoubleGrid(11, 11); // double 값에 대한 11x11 Grid 선언

	myIntGrid.at(0, 0) = 10;
	int x = myIntGrid.at(0, 0).value_or(0);

	Grid<int> grid2(myIntGrid);  // 복제 생성자
	Grid<int> anotherIntGrid;
	anotherIntGrid = grid2;      // 대입 연산자

	//Grid test;   // 컴파일 에러가 발생한다.
	//Grid<> test; // 컴파일 에러가 발생한다.

	processIntGrid(myIntGrid);

	Grid<SpreadsheetCell> mySpreadsheet;
	SpreadsheetCell myCell(1.234);
	mySpreadsheet.at(3, 4) = myCell;

	Grid<const char*> myStringGrid;
	myStringGrid.at(2, 2) = "hello";

	Grid<vector<int>> gridOfVectors;
	vector<int> myVector{ 1, 2, 3, 4 };
	gridOfVectors.at(5, 6) = myVector;

	auto myGridOnHeap = make_unique<Grid<int>>(2, 2); // 힙에 2x2 Grid 생성
	myGridOnHeap->at(0, 0) = 10;
	x = myGridOnHeap->at(0, 0).value_or(0);

	return 0;
}
