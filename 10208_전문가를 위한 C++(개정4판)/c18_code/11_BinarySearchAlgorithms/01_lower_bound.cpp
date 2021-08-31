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

	cout << "Sorted vector: ";
	for (const auto& i : vec) { cout << i << " "; }
	cout << endl;

	while (true) {
		int num;
		cout << "Enter a number to insert (0 to quit): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		
		auto iter = lower_bound(begin(vec), end(vec), num);
		vec.insert(iter, num);
		
		cout << "New vector: ";
		for (const auto& i : vec) { cout << i << " "; }
		cout << endl;
	}

	return 0;
}
