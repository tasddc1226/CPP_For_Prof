#include "Grid.h"
#include "SpreadsheetCell.h"
#include <vector>
#include <memory>

using namespace std;

void processIntGrid(Grid<int>& /*grid*/)
{
	// �ڵ� ����
}

int main()
{
	Grid<int> myIntGrid; // int ���� ������ Grid ��ü�� �����Ѵ�.
                         // �̶� �����ڿ� ����Ʈ �μ��� �����Ѵ�.
	Grid<double> myDoubleGrid(11, 11); // double ���� ���� 11x11 Grid ����

	myIntGrid.at(0, 0) = 10;
	int x = myIntGrid.at(0, 0).value_or(0);

	Grid<int> grid2(myIntGrid);  // ���� ������
	Grid<int> anotherIntGrid;
	anotherIntGrid = grid2;      // ���� ������

	//Grid test;   // ������ ������ �߻��Ѵ�.
	//Grid<> test; // ������ ������ �߻��Ѵ�.

	processIntGrid(myIntGrid);

	Grid<SpreadsheetCell> mySpreadsheet;
	SpreadsheetCell myCell(1.234);
	mySpreadsheet.at(3, 4) = myCell;

	Grid<const char*> myStringGrid;
	myStringGrid.at(2, 2) = "hello";

	Grid<vector<int>> gridOfVectors;
	vector<int> myVector{ 1, 2, 3, 4 };
	gridOfVectors.at(5, 6) = myVector;

	auto myGridOnHeap = make_unique<Grid<int>>(2, 2); // ���� 2x2 Grid ����
	myGridOnHeap->at(0, 0) = 10;
	x = myGridOnHeap->at(0, 0).value_or(0);

	return 0;
}
