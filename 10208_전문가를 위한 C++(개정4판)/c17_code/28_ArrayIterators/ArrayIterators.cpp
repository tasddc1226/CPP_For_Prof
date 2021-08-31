#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	const size_t count = 10;
	int arr[count];     // ǥ�� C ��Ÿ�� �迭

	// �迭�� �� ���Ҹ� ��� �ε��� ������ �ʱ�ȭ�Ѵ�.
	for (int i = 0; i < count; i++) {
		arr[i] = i;
	}

	// �迭�� ��� ������ vec �ڿ� �߰��Ѵ�.
	vector<int> vec;
	vec.insert(end(vec), arr, arr + count);
	// std::cbegin()�� std::cend()�� �ۼ��ϸ� ������ ����.
	//vec.insert(end(vec), cbegin(arr), cend(arr));

	// vec�ǳ����� ȭ�鿡 ����Ѵ�.
	for (const auto& i : vec) {
		cout << i << " ";
	}

	return 0;
}
