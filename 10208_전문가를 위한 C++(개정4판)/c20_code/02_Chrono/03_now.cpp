#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

int main()
{
	// ���� �ð��� time_point Ÿ������ �����´�.
	system_clock::time_point tpoint = system_clock::now();

	// time_t ������ ��ȯ�Ѵ�.
	time_t tt = system_clock::to_time_t(tpoint);

	// ���� �ð����� ��ȯ�Ѵ�.
	tm* t = localtime(&tt);
	// ����� �б� ���� �������� ��ȯ�Ѵ�.
	char buffer[80] = { 0 };
	strftime(buffer, sizeof(buffer), "%H:%M:%S", t);
	// ���� ����� �ֿܼ� ����Ѵ�.
	cout << buffer << endl;

	// �տ��� localtime()�� ȣ���ϴ� �κп��� ���� ��� ������ �߻��� �� �ִ�.
	// ����ũ�μ���Ʈ ���־� C++������ ������ ������ localtime_s()�� ȣ���ϵ���, 
	// ��������� localtime_r()�� ȣ���ϵ��� �����Ѵ�.
	// ���� ��� Visual C++�� ����� ���� �� ������ ������ ���� �ۼ��Ѵ�.
	//// ���� �ð����� ��ȯ�Ѵ�.
	//tm t;
	//localtime_s(&t, &tt);
	//// ����� �б� ���� �������� ��ȯ�Ѵ�.
	//char buffer[80] = { 0 };
	//strftime(buffer, sizeof(buffer), "%H:%M:%S", &t);
	//// ���� ����� �ֿܼ� ����Ѵ�.
	//cout << buffer << endl;

	return 0;
}
