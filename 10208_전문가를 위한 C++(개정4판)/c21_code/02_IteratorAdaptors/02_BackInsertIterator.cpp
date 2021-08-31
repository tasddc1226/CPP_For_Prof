#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

// int 컨테이너를 채우는 함수 템플릿
// 컨테이너는 반드시 push_back()을 제공해야 한다.
template<typename Container>
void populateContainer(Container& cont)
{
	int num;

	while (true) {
		cout << "Enter a number (0 to quit): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		cont.push_back(num);
	}
}

int main()
{
	vector<int> vectorOne, vectorTwo;
	populateContainer(vectorOne);

	back_insert_iterator<vector<int>> inserter(vectorTwo);
	copy_if(cbegin(vectorOne), cend(vectorOne), inserter,
		[](int i){ return i != 100; });

	//copy_if(cbegin(vectorOne), cend(vectorOne),
	//	back_inserter(vectorTwo), [](int i) { return i != 100; });

	// C++17의 생성자에 대한 템플릿 인수 추론 기능을 적용한 코드
	//copy_if(cbegin(vectorOne), cend(vectorOne),
	//	back_insert_iterator(vectorTwo), [](int i) { return i != 100; });

	copy(cbegin(vectorTwo), cend(vectorTwo), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
