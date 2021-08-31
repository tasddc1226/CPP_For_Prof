#include <cstddef>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
	vector<double> doubleVector; // double 값 열 개를 담은 vector를 생성한다.

	// 최댓값(max)을 double의 최솟값으로 초기화한다.
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
