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
		// �޸� �Ҵ� ������ ó���Ѵ�.
		return 1;
	}
	// �޸� �Ҵ翡 �����ߴٸ� �Լ��� ���������� �����Ѵ�.

	return 0;
}
