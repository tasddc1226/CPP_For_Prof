#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector(10);
	iota(begin(myVector), end(myVector), 1);	// ���͸� 1,2,3...10�� ä���.

	// ������ ������ ����Ѵ�.
	copy(cbegin(myVector), cend(myVector), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
