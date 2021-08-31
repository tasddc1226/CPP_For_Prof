#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

// int �����̳ʸ� ä��� �Լ� ���ø�
// �����̳ʴ� �ݵ�� push_back()�� �����ؾ� �Ѵ�.
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

	auto it1 = find(begin(myVector), end(myVector), num);		// it1�� Ÿ���� vector<int>::iterator
	auto it2 = find(rbegin(myVector), rend(myVector), num);		// it2�� Ÿ���� vector<int>::reverse_iterator

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
