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

	// 앞에서 vectorOne을 초기화할 때 깜박 잊고 넣지 않은 4를 여기서 추가한다.
	vectorOne.insert(cbegin(vectorOne) + 3, 4);

	// vectorTwo에 6부터 10까지의 원소를 추가한다.
	for (int i = 6; i <= 10; i++) {
		vectorTwo.push_back(i);
	}

	printVector(vectorOne);
	printVector(vectorTwo);

	// vectorTwo의 원소를 모두 vectorOne 뒤에 추가한다.
	vectorOne.insert(cend(vectorOne), cbegin(vectorTwo), cend(vectorTwo));
	printVector(vectorOne);

	// vectorOne에서 2부터 5까지 삭제한다.
	vectorOne.erase(cbegin(vectorOne) + 1, cbegin(vectorOne) + 5);
	printVector(vectorOne);

	// vectorTwo를 완전히 비운다.
	vectorTwo.clear();

	// 100에 대한 복제본 10개를 추가한다.
	vectorTwo.insert(cbegin(vectorTwo), 10, 100);

	// 마지막 원소를 제거해서 원소를 9개만 남긴다.
	vectorTwo.pop_back();
	printVector(vectorTwo);

	return 0;
}
