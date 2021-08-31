#include <iostream>
#include <fstream>
#include <string>
#include <string_view>

using namespace std;

// ������ �߻��ϸ� false�� �����Ѵ�.
bool changeNumberForID(string_view filename, int id, string_view newNumber);

int main()
{
	changeNumberForID("data.txt", 263, "415-555-3333");
	// data.txt ������ ������Ʈ ���� �ȿ� �����Ѵ�.
	// ������ ����� �ַ�� Ž���� â�� ������Ʈ �̸� ������ ���콺 ������ Ŭ���� ��
	// '���� Ž���⿡�� ���� ����'�� �����ؼ� ��Ÿ���� ���� �ȿ� data.txt ������ �ִ´�.

	return 0;
}

bool changeNumberForID(string_view filename, int id, string_view newNumber)
{
	fstream ioData(filename.data());
	if (!ioData) {
		cerr << "Error while opening file " << filename << endl;
		return false;
	}

	// ���� ������ �ݺ��Ѵ�.
	while (ioData) {
		int idRead;
		string number;

		// ���� ID�� �д´�.
		ioData >> idRead;
		if (!ioData)
			break;

		// ���� ���ڵ尡 ������ ������� Ȯ���Ѵ�.
		if (idRead == id) {
			// ���� ��ġ�� ���� �б� ��ġ�� �̵��Ѵ�.
			ioData.seekp(ioData.tellg());
			// �� ĭ ��� �� �� ��ȣ�� ����.
			ioData << " " << newNumber;
			break;
		}

		// ���� ��ġ���� ���ڸ� �о ��Ʈ���� ��ġ�� ���� ���ڵ�� �̵��Ѵ�.
		ioData >> number;
	}
	return true;
}