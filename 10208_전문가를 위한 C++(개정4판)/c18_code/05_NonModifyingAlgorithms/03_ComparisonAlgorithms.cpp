#include <algorithm>
#include <vector>
#include <list>
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
	vector<int> myVector;
	list<int> myList;

	cout << "Populate the vector:" << endl;
	populateContainer(myVector);
	cout << "Populate the list:" << endl;
	populateContainer(myList);

	// (C++14 �̻�) �� ���� �ݺ��ڸ� �޴� equal()�� mismatch()
	// �� �����̳ʰ� ������ ���Ѵ�.
	if (equal(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList))) {
		cout << "The two containers have equal elements" << endl;
	} else {
		// �� �����̳ʰ� �ٸ��� �� ������ �˾Ƴ���.
		auto miss = mismatch(cbegin(myVector), cend(myVector),
			cbegin(myList), cend(myList));
		cout << "The following initial elements are the same in "
			<< "the vector and the list:" << endl;
		for (auto i = cbegin(myVector); i != miss.first; ++i) {
			cout << *i << '\t';
		}
		cout << endl;
	}

	// (C++14 ����) �� ���� �ݺ��ڸ� �Է� �޴� equal()�� mismatch()
	//if (myList.size() == myVector.size() &&
	//	equal(cbegin(myVector), cend(myVector), cbegin(myList))) {
	//	cout << "The two containers have equal elements" << endl;
	//} else {
	//	if (myList.size() < myVector.size()) {
	//		cout << "Sorry, the list is not long enough." << endl;
	//		return 1;
	//	} else {
	//		// �� �����̳ʰ� �ٸ��� �� ������ �˾Ƴ���.
	//		auto miss = mismatch(cbegin(myVector), cend(myVector), cbegin(myList));
	//		cout << "The following initial elements are the same in the vector and the list:" << endl;
	//		for (auto i = cbegin(myVector); i != miss.first; ++i) {
	//			cout << *i << '\t';
	//		}
	//		cout << endl;
	//	}
	//}

	// �����̳ʸ� �����Ѵ�.
	if (lexicographical_compare(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList))) {
		cout << "The vector is lexicographically first." << endl;
	} else {
		cout << "The list is lexicographically first." << endl;
	}

	return 0;
}
