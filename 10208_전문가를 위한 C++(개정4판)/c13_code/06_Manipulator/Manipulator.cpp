#include <iostream>
#include <iomanip>
#include <locale>
#include <iomanip>

using namespace std;

int main()
{
	// �οﰪ
	bool myBool = true;
	cout << "This is the default: " << myBool << endl;
	cout << "This should be true: " << boolalpha << myBool << endl;
	cout << "This should be 1: " << noboolalpha << myBool << endl;

	// "%6d"�� ���� ȿ���� ��Ʈ���� �����ϴ� ���
	int i = 123;
	printf("This should be '   123': %6d\n", i);
	cout << "This should be '   123': " << setw(6) << i << endl;

	// "%06d"�� ���� ȿ���� ��Ʈ���� �����ϴ� ���
	printf("This should be '000123': %06d\n", i);
	cout << "This should be '000123': " << setfill('0') << setw(6) << i << endl;

	// *�� ä���
	cout << "This should be '***123': " << setfill('*') << setw(6) << i << endl;
	// �� ĭ ä��� ���� ����
	cout << setfill(' ');

	// �ε��Ҽ��� ��
	double dbl = 1.452;
	double dbl2 = 5;
	cout << "This should be ' 5': " << setw(2) << noshowpoint << dbl2 << endl;
	cout << "This should be @@1.452: " << setw(7) << setfill('@') << dbl << endl;
	// �� ĭ ä��� ���� ����
	cout << setfill(' ');

	// cout���� ���� ������ ����(����)�� �°� �����Ѵ�.
	// imbue() �޼���� locale ��ü�� 19�忡�� �ڼ��� �����Ѵ�.
	cout.imbue(locale(""));

	// ���� ������ �°� ���ڸ� ǥ���Ѵ�.
	cout << "This is 1234567 formatted according to your location: " << 1234567 << endl;

	// ȭ�� �ݾ��� ǥ���Ѵ�. ��Ȯ�� �׼��� ���� ����(����)�� �°� ǥ���Ѵ�.
    // ���� ��� �̱��̶�� 120000�� 120000 ��Ʈ�� �ǹ��Ѵ�.
    // �̸� �޷� ������ ǥ���ϸ� 1200.00�̴�.
	cout << "This should be a monetary value of 120000, "
		<< "formatted according to your location: "
		<< put_money("120000") << endl;

	// ��¥�� �ð�
#if !defined(_MSC_VER)
	time_t t_t = time(nullptr);  // ���� �ý��� �ð�
	tm* t = localtime(&t_t);     // ���� �ð����� ��ȯ
	cout << "This should be the current date and time formatted according to your location: "
		<< put_time(t, "%c") << endl;
#else
	// ���־� C++:
	time_t t_t = time(nullptr);
	tm t;
	localtime_s(&t, &t_t);
	cout << "This should be the current date and time formatted according to your location: "
		<< put_time(&t, "%c") << endl;
#endif

	// �ο� ��ȣ�� ���� ��Ʈ��
	cout << "This should be: \"Quoted string with \\\"embedded quotes\\\".\": "
		<< quoted("Quoted string with \"embedded quotes\".") << endl;

	// setprecision �Ŵ�ǽ������
	cout << "This should be '1.2346': " << setprecision(5) << 1.23456789 << endl;

	// precision() �޼���
	cout.precision(5);
	cout << "This should be '1.2346': " << 1.23456789 << endl;

	return 0;
}
