#include <iostream>
#include <string>
#include <string_view>
#include <cstddef>

using namespace std;

string_view extractExtension(string_view fileName)
{
	return fileName.substr(fileName.rfind('.'));
}

int main()
{
	// C++ std::string.
	string fileName = R"(c:\temp\my file.ext)";
	cout << "C++ string: " << extractExtension(fileName) << endl;

	// C-스타일 스트링.
	const char* cString = R"(c:\temp\my file.ext)";
	cout << "C string: " << extractExtension(cString) << endl;

	// 스트링 리터럴.
	cout << "Literal: " << extractExtension(R"(c:\temp\my file.ext)") << endl;

	// 버퍼 길이가 주어진 로 스트링
	const char* raw = "test.ext";
	size_t length = 8;
	cout << "Raw: " << extractExtension(string_view(raw, length)) << endl;

	// 결과를 std::string에 대입
	string extension = extractExtension(fileName).data();

	return 0;
}
