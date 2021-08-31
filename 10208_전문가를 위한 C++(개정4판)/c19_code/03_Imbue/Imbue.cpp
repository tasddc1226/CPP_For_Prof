#include <iostream>
#include <locale>

using namespace std;

int main()
{
	// ����� ȯ���� ������
	wcout.imbue(locale(""));
	wcout << 32767 << endl;

	// Ŭ����/��Ʈ�� ������
	wcout.imbue(locale("C"));
	wcout << 32767 << endl;

	// �̱��� ����
	wcout.imbue(locale("en-US")); // POSIX ������ "en_US"
	wcout << 32767 << endl;

	// �ѱ�
	wcout.imbue(locale("korean"));
	wcout << L"�ѱ�" << endl;

	return 0;
}
