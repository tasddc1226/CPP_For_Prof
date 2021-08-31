#include <list>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	// a�� �����ϴ� �ܾ� ����Ʈ�� �����.
	list<string> dictionary{ "aardvark", "ambulance" };

	// b�� �����ϴ� �ܾ� ����Ʈ�� �����.
	list<string> bWords{ "bathos", "balderdash" };

	// ù ��° ����Ʈ�� c�� �����ϴ� �ܾ �߰��Ѵ�.
	dictionary.push_back("canticle");
	dictionary.push_back("consumerism");

	// b�� �����ϴ� �ܾ ������ ����Ʈ�� ù ��° ����Ʈ�� �̾���δ�.
	if (!bWords.empty()) {
		// b�� �����ϴ� �ܾ� �� ������ �׸��� ����Ű�� �ݺ��ڸ� ���Ѵ�.
		auto iterLastB = --(cend(bWords));
		// b�� �����ϴ� �ܾ ���� ��ġ���� �ݺ��Ѵ�.
		auto it = cbegin(dictionary);
		for (; it != cend(dictionary); ++it) {
			if (*it > *iterLastB)
				break;
		}

		// b�� �����ϴ� �ܾ �߰��Ѵ�. �׷��� bWords�� �ִ� ���Ұ� �����ȴ�.
		dictionary.splice(it, bWords);
	}

	// ����� ȭ�鿡 ����Ѵ�.
	for (const auto& word : dictionary) {
		cout << word << endl;
	}

	return 0;
}
