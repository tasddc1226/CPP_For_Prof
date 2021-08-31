#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

// int 컨테이너를 채우는 함수 템플릿
// 컨테이너는 반드시 push_back()을 제공해야 한다.
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
	populateContainer(myVector);

	int num;
	cout << "Enter a number to find: ";
	cin >> num;

	auto it1 = find(begin(myVector), end(myVector), num);		// it1의 타입은 vector<int>::iterator
	auto it2 = find(rbegin(myVector), rend(myVector), num);		// it2의 타입은 vector<int>::reverse_iterator

	if (it1 != end(myVector)) {
		cout << "Found " << num << " at position " << it1 - begin(myVector)
			<< " going forward." << endl;
		cout << "Found " << num << " at position "
			<< it2.base() - 1 - begin(myVector) << " going backward." << endl;
	} else {
		cout << "Failed to find " << num << endl;
	}

	return 0;
}
