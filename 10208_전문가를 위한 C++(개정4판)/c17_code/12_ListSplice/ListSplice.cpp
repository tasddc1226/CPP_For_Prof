#include <list>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	// a로 시작하는 단어 리스트를 만든다.
	list<string> dictionary{ "aardvark", "ambulance" };

	// b로 시작하는 단어 리스트를 만든다.
	list<string> bWords{ "bathos", "balderdash" };

	// 첫 번째 리스트에 c로 시작하는 단어를 추가한다.
	dictionary.push_back("canticle");
	dictionary.push_back("consumerism");

	// b로 시작하는 단어를 저장한 리스트를 첫 번째 리스트에 이어붙인다.
	if (!bWords.empty()) {
		// b로 시작하는 단어 중 마지막 항목을 가리키는 반복자를 구한다.
		auto iterLastB = --(cend(bWords));
		// b로 시작하는 단어를 넣을 위치까지 반복한다.
		auto it = cbegin(dictionary);
		for (; it != cend(dictionary); ++it) {
			if (*it > *iterLastB)
				break;
		}

		// b로 시작하는 단어를 추가한다. 그러면 bWords에 있던 원소가 삭제된다.
		dictionary.splice(it, bWords);
	}

	// 결과를 화면에 출력한다.
	for (const auto& word : dictionary) {
		cout << word << endl;
	}

	return 0;
}
