#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	// ����: input.txt�� �ݵ�� �־�� �Ѵ�.
	// ������ ����� �ַ�� Ž���� â�� ������Ʈ �̸� ������ ���콺 ������ Ŭ���� ��
	// '���� Ž���⿡�� ���� ����'�� �����ؼ� ��Ÿ���� ���� �ȿ� input.txt ������ �����.
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	// inFile�� outFile�� �����Ѵ�.
	inFile.tie(&outFile);
	// outFile�� �ؽ�Ʈ�� ����. std::endl�� �ԷµǱ� �������� �������� �ʴ´�.
	outFile << "Hello there!";
	// outFile�� ���� �������� ���� ���´�.
	// inFile���� �ؽ�Ʈ�� �д´�. �׷��� outFile�� ���� flush()�� ȣ��ȴ�.
	string nextToken;
	inFile >> nextToken;
	// ���� outFile�� ����������.

	return 0;
}
