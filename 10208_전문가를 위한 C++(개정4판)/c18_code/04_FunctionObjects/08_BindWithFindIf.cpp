#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

int main()
{
	int num;

	vector<int> myVector;
	while (true) {
		cout << "Enter a test score to add (0 to stop): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		myVector.push_back(num);
	}

	auto endIter = end(myVector);
	
	// std::bind와 투명 함수 객체를 이용하는 C++14 방식 코드
	auto it = find_if(begin(myVector), endIter,
		bind(greater_equal<>(), placeholders::_1, 100));

	// 권장하는 C++11/C++14 방식: 람다를 사용한다.
	//auto it = find_if(begin(myVector), endIter, [](int i){ return i >= 100; });
	
	if (it == endIter) {
		cout << "No perfect scores" << endl;
	} else {
		cout << "Found a \"perfect\" score of " << *it << endl;
	}
	return 0;
}
