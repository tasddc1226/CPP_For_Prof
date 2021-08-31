#include <vector>

using namespace std;

int main()
{
	vector<int> intVector;

	auto iter = end(intVector);
	*iter = 10; // 버그! iter는 벡터 원소를 가리키지 않고 있다.

	vector<int> vectorOne(10);
	vector<int> vectorTwo(10);

	// 벡터에 원소를 채운다.

	// 버그! 무한 루프에 빠질 수 있다.
	for (auto iter = begin(vectorTwo); iter != end(vectorOne); ++iter) {
		// 루프 본문
	}

	return 0;
}
