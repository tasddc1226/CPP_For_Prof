#include <cstddef>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
	size_t integerCount = numeric_limits<size_t>::max();
	cout << "Trying to allocate memory for " << integerCount << " integers." << endl;

	int* ptr = new(nothrow) int[integerCount];
	if (ptr == nullptr) {
		cerr << __FILE__ << "(" << __LINE__ << "): Unable to allocate memory!" << endl;
		// �޸� �Ҵ� ������ ó���Ѵ�.
		return 1;
	}
	// �޸� �Ҵ翡 �����ߴٸ� �Լ��� ���������� �����Ѵ�.

	return 0;
}
