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
	// ���� ��� for���� ����� ����, �� �ڵ带 ����Ϸ��� �տ� ���� for���� �ּ�ó���Ѵ�.
	for (auto& str : stringVector) {
		str.append(" there");
		cout << str << endl;
	}
*/
	return 0;
}
