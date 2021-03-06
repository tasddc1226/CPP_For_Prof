#include <iostream>

using namespace std;

int main()
{
	const char* s1 = u8R"(Raw UTF-8 encoded string literal)";
	const wchar_t* s2 = LR"(Raw wide string literal)";
	const char16_t* s3 = uR"(Raw char16_t string literal)";
	const char32_t* s4 = UR"(Raw char32_t string literal)";

	cout << s1 << endl;
	wcout << s2 << endl;
	// 스트림은 char16_t and char32_t 타입을 지원하지 않으므로 s3과 s4는 스트림에 출력할 수 없다.

	const char* formula = u8"\u03C0 r\u00B2";

	return 0;
}
