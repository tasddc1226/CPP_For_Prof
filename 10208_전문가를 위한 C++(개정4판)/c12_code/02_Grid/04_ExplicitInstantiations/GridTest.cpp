#include "Grid.h"
#include <vector>

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

	processIntGrid(myIntGrid);

	Grid<vector<int>> gridOfVectors;
	vector<int> myVector{ 1, 2, 3, 4 };
	gridOfVectors.at(5, 6) = myVector;

	return 0;
}
