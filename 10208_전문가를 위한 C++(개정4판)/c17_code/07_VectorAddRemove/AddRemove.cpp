#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void printVector(const vector<T>& v)
{
	for (auto& element : v)
	{
		cout << element << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vectorOne = { 1, 2, 3, 5 };
	vector<int> vectorTwo;

	// �տ��� vectorOne�� �ʱ�ȭ�� �� ���� �ذ� ���� ���� 4�� ���⼭ �߰��Ѵ�.
	vectorOne.insert(cbegin(vectorOne) + 3, 4);

	// vectorTwo�� 6���� 10������ ���Ҹ� �߰��Ѵ�.
	for (int i = 6; i <= 10; i++) {
		vectorTwo.push_back(i);
	}

	printVector(vectorOne);
	printVector(vectorTwo);

	// vectorTwo�� ���Ҹ� ��� vectorOne �ڿ� �߰��Ѵ�.
	vectorOne.insert(cend(vectorOne), cbegin(vectorTwo), cend(vectorTwo));
	printVector(vectorOne);

	// vectorOne���� 2���� 5���� �����Ѵ�.
	vectorOne.erase(cbegin(vectorOne) + 1, cbegin(vectorOne) + 5);
	printVector(vectorOne);

	// vectorTwo�� ������ ����.
	vectorTwo.clear();

	// 100�� ���� ������ 10���� �߰��Ѵ�.
	vectorTwo.insert(cbegin(vectorTwo), 10, 100);

	// ������ ���Ҹ� �����ؼ� ���Ҹ� 9���� �����.
	vectorTwo.pop_back();
	printVector(vectorTwo);

	return 0;
}
