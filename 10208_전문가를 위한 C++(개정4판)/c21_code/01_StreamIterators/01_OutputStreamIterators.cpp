#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector(10);
	iota(begin(myVector), end(myVector), 1);	// 벡터를 1,2,3...10로 채운다.

	// 벡터의 내용을 출력한다.
	copy(cbegin(myVector), cend(myVector), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
