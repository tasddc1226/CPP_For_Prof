#include <vector>

using namespace std;

int main()
{
	vector<int> intVector;

	auto iter = end(intVector);
	*iter = 10; // ����! iter�� ���� ���Ҹ� ����Ű�� �ʰ� �ִ�.

	vector<int> vectorOne(10);
	vector<int> vectorTwo(10);

	// ���Ϳ� ���Ҹ� ä���.

	// ����! ���� ������ ���� �� �ִ�.
	for (auto iter = begin(vectorTwo); iter != end(vectorOne); ++iter) {
		// ���� ����
	}

	return 0;
}
