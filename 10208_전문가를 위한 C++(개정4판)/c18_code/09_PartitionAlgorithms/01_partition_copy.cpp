#include <algorithm>
#include <vector>
#include <iostream>

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

int main()
{
	vector<int> vec1, vecOdd, vecEven;

	populateContainer(vec1);

	vecOdd.resize(size(vec1));
	vecEven.resize(size(vec1));

	auto pairIters = partition_copy(cbegin(vec1), cend(vec1),
		begin(vecEven), begin(vecOdd),
		[](int i){ return i % 2 == 0; });

	vecEven.erase(pairIters.first, end(vecEven));
	vecOdd.erase(pairIters.second, end(vecOdd));

	cout << "Even numbers: ";
	for (const auto& i : vecEven) { cout << i << " "; }
	cout << endl << "Odd numbers: ";
	for (const auto& i : vecOdd) { cout << i << " "; }
	cout << endl;

	return 0;
}
