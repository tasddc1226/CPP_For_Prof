#include <iostream>
#include <memory>
#include "GridPtr.h"

using namespace std;

int main()
{
	Grid<int> myIntGrid;     // 특수화하지 않은 버전의 그리드를 사용한다.
	Grid<int*> psGrid(2, 2); // 포인터 타입에 대한 부분 특수화 버전을 사용한다.

	psGrid.at(0, 0) = make_unique<int>(1);
	psGrid.at(0, 1) = make_unique<int>(2);
	psGrid.at(1, 0) = make_unique<int>(3);

	Grid<int*> psGrid2(psGrid);
	Grid<int*> psGrid3;
	psGrid3 = psGrid2;

	auto& element = psGrid2.at(1, 0);
	if (element) {
		cout << *element << endl;
		*element = 6;
	}
	cout << *psGrid.at(1, 0) << endl;  // psGrid는 수정되지 않았다.
	cout << *psGrid2.at(1, 0) << endl; // psGrid2는 수정됐다.

	return 0;
}
