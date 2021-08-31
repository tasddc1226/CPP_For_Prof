#include <cstddef>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	char text1[] = "abcdef";
	size_t s1 = sizeof(text1);  //  7
	size_t s2 = strlen(text1);  //  6
	cout << s1 << endl << s2 << endl;

	const char* text2 = "abcdef";
	size_t s3 = sizeof(text2);  // �÷������� �ٸ���. (��, x86�� 4����Ʈ, x64�� 8����Ʈ)
	size_t s4 = strlen(text2);  // 6
	cout << s3 << endl << s4 << endl;

	return 0;
}
