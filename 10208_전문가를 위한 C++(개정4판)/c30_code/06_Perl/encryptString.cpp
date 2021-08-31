#include <iostream>
#include <string>
#include <string_view>

using namespace std;

string encrypt(string_view input);

int main(int argc, char* argv[])
{
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " string-to-be-encrypted" << endl;
		return -1;
	}

	cout << encrypt(argv[1]);

	return 0;
} 

// �־��� ��Ʈ���� �� ���ڸ��� 13�� ���ϴ�
// ������ ����� ��ȣȭ�� �����Ѵ�.
string encrypt(string_view input)
{
	string encrypted = input.data();
	for (auto& character : encrypted) {
		character += 13;
	}
	return encrypted;
}
