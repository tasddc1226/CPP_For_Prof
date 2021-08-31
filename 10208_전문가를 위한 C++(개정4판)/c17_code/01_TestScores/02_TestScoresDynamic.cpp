#include <cstddef>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
	vector<double> doubleVector; // double �� �� ���� ���� vector�� �����Ѵ�.

	// �ִ�(max)�� double�� �ּڰ����� �ʱ�ȭ�Ѵ�.
	double max = -numeric_limits<double>::infinity();

	for (size_t i = 1; true; i++) {
		double temp;
		cout << "Enter score " << i << " (-1 to stop): ";
		cin >> temp;
		if (temp == -1) {
			break;
		}
		doubleVector.push_back(temp);
		if (temp > max) {
			max = temp;
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
