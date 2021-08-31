#include <algorithm>
#include <vector>
#include <iostream>
#include <string_view>

using namespace std;

// int Ÿ�� �����̳ʿ� ���Ҹ� ä��� �Լ� ���ø�
// �̶� �����̳ʴ� �ݵ�� push_back()�� �����ؾ� �Ѵ�.
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

	// �� �����̳ʸ� �����Ѵ�.
	sort(begin(vectorOne), end(vectorOne));
	sort(begin(vectorTwo), end(vectorTwo));

	// �� ���� ���͸� ��ģ ���� ��� ���� ������ ��� vector�� ũ�⸦ �˳��� Ȯ���Ѵ�.
	vectorMerged.resize(size(vectorOne) + size(vectorTwo));

	merge(cbegin(vectorOne), cend(vectorOne),
		cbegin(vectorTwo), cend(vectorTwo), begin(vectorMerged));

	DumpRange("Merged vector: ", cbegin(vectorMerged), cend(vectorMerged));

	return 0;
}
