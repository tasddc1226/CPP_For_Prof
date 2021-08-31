#include <algorithm>
#include <vector>
#include <iostream>
#include <string_view>

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

template<typename Iterator>
void DumpRange(string_view message, Iterator begin, Iterator end)
{
	cout << message;
	for_each(begin, end, [](const auto& element) { cout << element << " "; });
	cout << endl;
}

int main()
{
	vector<int> vectorOne, vectorTwo, vectorMerged;
	cout << "Enter values for first vector:" << endl;
	populateContainer(vectorOne);
	cout << "Enter values for second vector:" << endl;
	populateContainer(vectorTwo);

	// 두 컨테이너를 정렬한다.
	sort(begin(vectorOne), end(vectorOne));
	sort(begin(vectorTwo), end(vectorTwo));

	// 두 원본 벡터를 합친 값을 모두 담을 정도로 대상 vector의 크기를 넉넉히 확보한다.
	vectorMerged.resize(size(vectorOne) + size(vectorTwo));

	merge(cbegin(vectorOne), cend(vectorOne),
		cbegin(vectorTwo), cend(vectorTwo), begin(vectorMerged));

	DumpRange("Merged vector: ", cbegin(vectorMerged), cend(vectorMerged));

	return 0;
}
