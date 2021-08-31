#include <cstddef>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
	vector<double> doubleVector(10); // double �� �� ���� ���� vector�� �����Ѵ�.

	// �ִ�(max)�� double�� �ּڰ����� �ʱ�ȭ�Ѵ�.
	double max = -numeric_limits<double>::infinity();

	for (size_t i = 0; i < doubleVector.size(); i++) {
		cout << "Enter score " << i + 1 << ": ";
		cin >> doubleVector[i];
		if (doubleVector[i] > max) {
			max = doubleVector[i];
		}
	}

	max /= 100.0;
	for (auto& element : doubleVector) {
		element /= max;
		cout << element << " ";
	}
	cout << endl;
	return 0;
}
