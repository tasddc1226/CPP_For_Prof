#include "Grid.h"
#include <vector>

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

	processIntGrid(myIntGrid);

	Grid<vector<int>> gridOfVectors;
	vector<int> myVector{ 1, 2, 3, 4 };
	gridOfVectors.at(5, 6) = myVector;

	return 0;
}
