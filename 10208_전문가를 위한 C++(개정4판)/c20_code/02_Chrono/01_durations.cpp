#include <iostream>
#include <chrono>
#include <ratio>

using namespace std;
using namespace std::chrono;

int main()
{
	// �� ƽ�� 60���� duration�� �����Ѵ�.
	duration<long, ratio<60>> d1(123);
	cout << d1.count() << endl;

	// �� ƽ�� 1�ʰ�, �ִ� duration�� �Ҵ��� �� �ִ�,
	// double ������ ǥ���ϴ� duration�� �����Ѵ�.
	duration<double> d2;
	d2 = d2.max();
	cout << d2.count() << endl;

	// �� ���� duration�� �����Ѵ�.
	// �ϳ��� �� ƽ�� 1���̰�, �ٸ� �ϳ��� �� ƽ�� 1�ʴ�.
	duration<long, ratio<60>> d3(10);  // = 10��
	duration<long, ratio<1>> d4(14);   // = 14��

	// �� duration�� ���Ѵ�.
	if (d3 > d4)
		cout << "d3 > d4" << endl;
	else
		cout << "d3 <= d4" << endl;

	// d4�� 1��ŭ �������� 15�ʷ� �����.
	++d4;

	// d4�� 2�� ���� 30�ʷ� �����.
	d4 *= 2;

	// �� duration�� ���ؼ� �� ���� duration�� �����Ѵ�.
	duration<double, ratio<60>> d5 = d3 + d4;

	// �� duration�� ���ؼ� �� ���� duration�� �����Ѵ�.
	duration<long, ratio<1>> d6 = d3 + d4;
	cout << d3.count() << " minutes + " << d4.count() << " seconds = "
		<< d5.count() << " minutes or "
		<< d6.count() << " seconds" << endl;

	// 30�� duration�� �����Ѵ�.
	duration<long> d7(30);

	// �� ������ d7�� �� ������ ��ȯ�Ѵ�.
	duration<double, ratio<60>> d8(d7);
	cout << d7.count() << " seconds = " << d8.count() << " minutes" << endl;

	// duration_cast()�� �̿��Ͽ� �� ���� d7�� ������ ������ ��ȯ�Ѵ�.
	auto d8_ = duration_cast<duration<long, ratio<60>>>(d7);    // minutes
	cout << d8_.count() << endl;

	// ������ ���� ������ �ʷ� ��ȯ�Ѵ�.
	duration<long, ratio<60>> d9(10);    // ��
	//minutes d9(10);                      // ��
	duration<long> d10(d9);              // ��
	cout << d10.count() << endl;

	// �̸� ���ǵ� duration�� ����Ѵ�.
	auto t = hours(1) + minutes(23) + seconds(45);
	cout << seconds(t).count() << " seconds" << endl;

	// ǥ�� ����� ���� ���ͷ�
	auto myDuration = 42min;    // 42��

	return 0;
}
