#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

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
	vector<int> vec1, vec2;
	cout << "Vector1:" << endl; populateContainer(vec1);
	cout << "Vector2:" << endl; populateContainer(vec2);

	if (vec2.size() < vec1.size())
	{
		cout << "Vector2 should be at least the same size as vector1." << endl;
		return 1;
	}

	// 컨테이너의 내용을 출력하는 람다 표현식을 만든다.
	auto printContainer = [](const auto& container) {
		for (auto& i : container) { cout << i << " "; }
		cout << endl;
	};

	cout << "Vector1: "; printContainer(vec1);
	cout << "Vector2: "; printContainer(vec2);

	transform(begin(vec1), end(vec1), begin(vec2), begin(vec1),
		[](int a, int b){ return a + b; });

	cout << "Vector1: "; printContainer(vec1);
	cout << "Vector2: "; printContainer(vec2);


	return 0;
}
