#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// Ž���� ���� ���
	vector<int> myVector = { 5, 6, 9, 8, 8, 3 };
	auto beginIter = cbegin(myVector);
	auto endIter = cend(myVector);

	// �־��� ���� ǥ������ �������� �ʴ� ù ��° ���Ҹ� ã�´�.
	auto it = find_if_not(beginIter, endIter, [](int i){ return i < 8; });
	if (it != endIter) {
		cout << "First element not < 8 is " << *it << endl;
	}

	// ���� ���� ���ӵ� ù ��° ���� ���� ã�´�.
	it = adjacent_find(beginIter, endIter);
	if (it != endIter) {
		cout << "Found two consecutive equal elements with value " << *it << endl;
	}

	// �� �� �� ���� ������ ���� ã�´�.
	vector<int> targets = { 8, 9 };
	it = find_first_of(beginIter, endIter, cbegin(targets), cend(targets));
	if (it != endIter) {
		cout << "Found one of 8 or 9: " << *it << endl;
	}

	// ù ��° �κп��� ã�´�.
	vector<int> sub = { 8, 3 };
	it = search(beginIter, endIter, cbegin(sub), cend(sub));
	if (it != endIter) {
		cout << "Found subsequence {8,3}" << endl;
	} else {
		cout << "Unable to find subsequence {8,3}" << endl;
	}

	// ������ �κп��� ã�´�. (�� ���������� ù ��° �κп��� ����.)
	auto it2 = find_end(beginIter, endIter, cbegin(sub), cend(sub));
	if (it != it2) {
		cout << "Error: search and find_end found different subsequences "
			<< "even though there is only one match." << endl;
	}

	// 8�� �� �� ���ӵ� ù ��° �κп��� ã�´�.
	it = search_n(beginIter, endIter, 2, 8);
	if (it != endIter) {
		cout << "Found two consecutive 8s" << endl;
	} else {
		cout << "Unable to find two consecutive 8s" << endl;
	}

	return 0;
}
