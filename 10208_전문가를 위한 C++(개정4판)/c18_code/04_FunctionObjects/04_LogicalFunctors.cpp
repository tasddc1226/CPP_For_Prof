#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

bool allTrue(const vector<bool>& flags)
{
	return accumulate(begin(flags), end(flags), true, logical_and<>());			// C++14 투명 연산자 펑터를 사용한 코드
	//return accumulate(begin(flags), end(flags), true, logical_and<bool>());	// C++14 이전 버전
}

bool anyTrue(const vector<bool>& flags)
{
	return accumulate(begin(flags), end(flags), false, logical_or<>());			// C++14 투명 연산자 펑터를 사용한 코드
	//return accumulate(begin(flags), end(flags), false, logical_or<bool>());	// C++14 이전 버전
}

int main()
{
	vector<bool> myVector;
	int num;
	while (true) {
		cout << "Enter a value 0 or 1 to add (-1 to stop): ";
		cin >> num;
		if (num == -1) {
			break;
		}
		myVector.push_back(num == 1);
	}

	cout << "allTrue? " << (allTrue(myVector) ? "yes" : "no") << endl;
	cout << "anyTrue? " << (anyTrue(myVector) ? "yes" : "no") << endl;

	return 0;
}
