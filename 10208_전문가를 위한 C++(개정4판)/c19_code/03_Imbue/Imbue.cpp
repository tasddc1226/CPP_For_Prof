#include <iostream>
#include <locale>

using namespace std;

int main()
{
	// 사용자 환경의 로케일
	wcout.imbue(locale(""));
	wcout << 32767 << endl;

	// 클래식/뉴트럴 로케일
	wcout.imbue(locale("C"));
	wcout << 32767 << endl;

	// 미국식 영어
	wcout.imbue(locale("en-US")); // POSIX 포맷은 "en_US"
	wcout << 32767 << endl;

	// 한국
	wcout.imbue(locale("korean"));
	wcout << L"한글" << endl;

	return 0;
}
