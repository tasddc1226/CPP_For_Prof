#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

int main()
{
	// ���� �ð��� �����´�.
	auto start = high_resolution_clock::now();
	
	// �ð��� ��� ���� �ڵ带 �����Ѵ�.
	
	double d = 0;
	for (int i = 0; i < 1000000; ++i) {
		d += sqrt(sin(i) * cos(i));
	}
	// �� �ð��� ���ؼ� ���� �ð����� ���� ���Ѵ�.
	auto end = high_resolution_clock::now();
	auto diff = end - start;
	// ���� �ð� ���� ms ������ ��ȯ�ؼ� �ֿܼ� ����Ѵ�.
	cout << duration<double, milli>(diff).count() << "ms" << endl;

	// d�� ����Ѵ�. �׷��� ������ �տ� ���� �ݺ��� ��ü�� �����Ϸ��� ����ȭ�ع��� �� �ִ�.
	cout << d << endl;

	return 0;
}
