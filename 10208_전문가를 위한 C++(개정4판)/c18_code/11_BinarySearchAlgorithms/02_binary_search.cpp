#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// int 타입 컨테이너에 원소를 채우는 함수 템플릿
// 이때 컨테이너는 반드시 push_back()을 제공해야 한다.
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
	vector<int> vec;
	populateContainer(vec);

	// 컨테이너를 정렬한다.
	sort(begin(vec), end(vec));

	while (true) {
		int num;
		cout << "Enter a number to find (0 to quit): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		if (binary_search(cbegin(vec), cend(vec), num)) {
			cout << "That number is in the vector." << endl;
		} else {
			cout << "That number is not in the vector." << endl;
		}
	}

	return 0;
}
