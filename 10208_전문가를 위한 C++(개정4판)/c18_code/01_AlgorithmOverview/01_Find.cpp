#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int num;

	vector<int> myVector;
	while (true) {
		cout << "Enter a number to add (0 to stop): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		myVector.push_back(num);
	}

	while (true) {
		cout << "Enter a number to lookup (0 to stop): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		
		auto endIt = cend(myVector);

		auto it = find(cbegin(myVector), endIt, num);
		if (it == endIt) {
			cout << "Could not find " << num << endl;
		} else {
			cout << "Found " << *it << endl;
		}

		// C++17부터 추가된 if문의 이니셜라이저를 사용한 코드
		//if (auto it = find(cbegin(myVector), endIt, num); it == endIt) {
		//	cout << "Could not find " << num << endl;
		//} else {
		//	cout << "Found " << *it << endl;
		//}
	}

	return 0;
}
