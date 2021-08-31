#include <cstddef>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
	int* ptr = nullptr;
	size_t integerCount = numeric_limits<size_t>::max();
	cout << "Trying to allocate memory for " << integerCount << " integers." << endl;

	try {
		ptr = new int[integerCount];
	} catch (const bad_alloc& e) {
		cerr << __FILE__ << "(" << __LINE__ << "): Unable to allocate memory: " << e.what() << endl;
		// 메모리 할당 에러를 처리한다.
		return 1;
	}
	// 메모리 할당에 성공했다면 함수를 정상적으로 진행한다.

	return 0;
}
