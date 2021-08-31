#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int x = 4, y = 5;
	cout << "x is " << x << " and y is " << y << endl;
	cout << "Max is " << max(x, y) << endl;
	cout << "Min is " << min(x, y) << endl;

	// �� �� �̻��� ���� ���� max()�� min()�� ���ϴ� ��
	int x1 = 2, x2 = 9, x3 = 3, x4 = 12;
	cout << "Max of 4 elements is " << max({ x1, x2, x3, x4 }) << endl;
	cout << "Min of 4 elements is " << min({ x1, x2, x3, x4 }) << endl;
	
	// minmax()�� ���ϴ� ��
	auto p2 = minmax({ x1, x2, x3, x4 });	// p2 is of type pair<int, int>
	cout << "Minmax of 4 elements is <"
		<< p2.first << "," << p2.second << ">" << endl;

	// minmax() + C++17 ������ ���ε�
	auto[min1, max1] = minmax({ x1, x2, x3, x4 });
	cout << "Minmax of 4 elements is <"
		<< min1 << "," << max1 << ">" << endl;

	// minmax_element() + C++17 ������ ���ε�
	vector<int> vec{ 11, 33, 22 };
	auto[min2, max2] = minmax_element(cbegin(vec), cend(vec));
	cout << "minmax_element() result: <"
		<< *min2 << "," << *max2 << ">" << endl;
		
	return 0;
}
