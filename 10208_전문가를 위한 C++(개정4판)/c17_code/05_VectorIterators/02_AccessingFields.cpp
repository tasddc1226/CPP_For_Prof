#include <vector>
#include <string>
#include <iostream> // for cout

using namespace std;

int main()
{
	vector<string> stringVector(10, "hello");

	for (auto it = begin(stringVector); it != end(stringVector); ++it) {
		it->append(" there");
		cout << *it << endl;
	}
/*
	// 범위 기반 for문을 사용한 버전, 이 코드를 사용하려면 앞에 나온 for문을 주석처리한다.
	for (auto& str : stringVector) {
		str.append(" there");
		cout << str << endl;
	}
*/
	return 0;
}
