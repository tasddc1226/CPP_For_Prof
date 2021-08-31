#include <iostream>
#include <array>

using namespace std;

int main()
{
	// ���� �� ���� ������ �迭�� �����Ѵ�.
	// �̶� ������ initializer_list�� �ʱ�ȭ�Ѵ�. (������ �ʱ�ȭ)
	array<int, 3> arr = { 9, 8, 7 };
	// �迭�� ũ�⸦ ȭ�鿡 ����Ѵ�.
	cout << "Array size = " << arr.size() << endl; // �Ǵ� std::size(arr);
	// ���� ��� for������ �迭�� ������ ȭ�鿡 ����Ѵ�.
	for (const auto& i : arr) {
		cout << i << endl;
	}

	cout << "Performing arr.fill(3)..." << endl;
	// fill �޼���� �迭�� ������ �����Ѵ�.
	arr.fill(3);
	// �ݺ��ڷ� �迭�� ���Ҹ� ��� ����Ѵ�.
	for (auto iter = cbegin(arr); iter != cend(arr); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}
