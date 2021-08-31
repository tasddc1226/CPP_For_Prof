#include <cstddef>
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
	vector<int> vec1, vec2;

	populateContainer(vec1);

	size_t cnt = 0;
	cout << "Enter number of elements you want to copy: ";
	cin >> cnt;
	cnt = min(cnt, size(vec1));
	vec2.resize(cnt);
	copy_n(cbegin(vec1), cnt, begin(vec2));
	for (const auto& i : vec2) { cout << i << " "; }

	cout << endl;

	return 0;
}
