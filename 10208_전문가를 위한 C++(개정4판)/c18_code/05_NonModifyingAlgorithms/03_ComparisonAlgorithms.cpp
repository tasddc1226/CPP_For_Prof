#include <algorithm>
#include <vector>
#include <list>
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
	vector<int> myVector;
	list<int> myList;

	cout << "Populate the vector:" << endl;
	populateContainer(myVector);
	cout << "Populate the list:" << endl;
	populateContainer(myList);

	// (C++14 이상) 네 가지 반복자를 받는 equal()과 mismatch()
	// 두 컨테이너가 같은지 비교한다.
	if (equal(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList))) {
		cout << "The two containers have equal elements" << endl;
	} else {
		// 두 컨테이너가 다르면 그 이유를 알아낸다.
		auto miss = mismatch(cbegin(myVector), cend(myVector),
			cbegin(myList), cend(myList));
		cout << "The following initial elements are the same in "
			<< "the vector and the list:" << endl;
		for (auto i = cbegin(myVector); i != miss.first; ++i) {
			cout << *i << '\t';
		}
		cout << endl;
	}

	// (C++14 이전) 세 가지 반복자를 입력 받는 equal()과 mismatch()
	//if (myList.size() == myVector.size() &&
	//	equal(cbegin(myVector), cend(myVector), cbegin(myList))) {
	//	cout << "The two containers have equal elements" << endl;
	//} else {
	//	if (myList.size() < myVector.size()) {
	//		cout << "Sorry, the list is not long enough." << endl;
	//		return 1;
	//	} else {
	//		// 두 컨테이너가 다르면 그 이유를 알아낸다.
	//		auto miss = mismatch(cbegin(myVector), cend(myVector), cbegin(myList));
	//		cout << "The following initial elements are the same in the vector and the list:" << endl;
	//		for (auto i = cbegin(myVector); i != miss.first; ++i) {
	//			cout << *i << '\t';
	//		}
	//		cout << endl;
	//	}
	//}

	// 컨테이너를 정렬한다.
	if (lexicographical_compare(cbegin(myVector), cend(myVector), cbegin(myList), cend(myList))) {
		cout << "The vector is lexicographically first." << endl;
	} else {
		cout << "The list is lexicographically first." << endl;
	}

	return 0;
}
