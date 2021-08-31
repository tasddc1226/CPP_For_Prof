#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	// ����� steady_clock�� ���� ����ũ�� ǥ���ϴ� time_point�� �����Ѵ�.
	time_point<steady_clock> tp1;
	// �Ǵ� ������ ���� �ۼ��Ѵ�.
	// steady_clock::time_point tp1;

	// �� time_point�� 10���� ���Ѵ�.
	tp1 += minutes(10);
	// ����ũ�� time_point ������ duration�� �����Ѵ�.
	auto d1 = tp1.time_since_epoch();
	// duration�� �� ������ ��ȯ�ؼ� ����� �ֿܼ� ����Ѵ�.
	duration<double> d2(d1);
	cout << d2.count() << " seconds" << endl;

	return 0;
}
