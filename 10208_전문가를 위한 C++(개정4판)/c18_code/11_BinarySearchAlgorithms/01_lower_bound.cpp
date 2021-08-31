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
	vector<int> vec;
	populateContainer(vec);

	// �����̳ʸ� �����Ѵ�.
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
