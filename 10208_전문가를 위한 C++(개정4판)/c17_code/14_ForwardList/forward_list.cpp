#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	// forward_list �� ���� �����Ѵ�.
	// �̶� ���Ҹ� initializer_list�� �ʱ�ȭ�Ѵ�. (������ �ʱ�ȭ)
	// to initialize their elements (uniform initialization).
	forward_list<int> list1 = { 5, 6 };
	forward_list<int> list2 = { 1, 2, 3, 4 };
	forward_list<int> list3 = { 7, 8, 9 };

	// splice �������� list1 �տ� list2�� �߰��Ѵ�.
	list1.splice_after(list1.before_begin(), list2);

	// list1 �� �տ� ���� 0�� �߰��Ѵ�.
	list1.push_front(0);

	// list1 �ڿ� list3�� �߰��Ѵ�.
	// �̸� ���� ���� ������ ���ҿ� ���� �ݺ��ڸ� ���Ѵ�.
	auto iter = list1.before_begin();
	auto iterTemp = iter;
	while (++iterTemp != end(list1)) {
		++iter;
	}
	list1.insert_after(iter, cbegin(list3), cend(list3));

	// list1�� ������ ȭ�鿡 ����Ѵ�.
	for (auto& i : list1) {
		cout << i << ' ';
	}

	return 0;
}
