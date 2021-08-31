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

// 주어진 스트링의 각 문자마다 13을 더하는
// 가벼운 방식의 암호화를 수행한다.
string encrypt(string_view input)
{
	string encrypted = input.data();
	for (auto& character : encrypted) {
		character += 13;
	}
	return encrypted;
}
