#include <cstddef>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
	vector<double> doubleVector;
	// max를 최솟값으로 초기화한다.
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
	
	for (vector<double>::iterator iter = begin(doubleVector);
		iter != end(doubleVector); ++iter) {
		*iter /= max;
		cout << *iter << " ";
	}
	cout << endl;
	
/*
	// auto 키워드를 사용한 버전, 이 코드를 사용하려면 앞에 나온 for문을 주석처리한다.
	for (auto iter = begin(doubleVector);
		iter != end(doubleVector); ++iter) {
		*iter /= max;
		cout << *iter << " ";
	}
	cout << endl;
*/

	return 0;
}
