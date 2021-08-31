#include <iostream>
#include <ratio>

using namespace std;

int main()
{
	// 컴파일 시간 유리수 정의
	using r1 = ratio<1, 60>;
	cout << "1) " << r1::num << "/" << r1::den << endl;

	// 분자와 분모 생성
	intmax_t num = r1::num;
	intmax_t den = r1::den;
	cout << "2) " << num << "/" << den << endl;

	// 두 유리수를 더한다.
	using r2 = ratio<1, 30>;
	cout << "3) " << r2::num << "/" << r2::den << endl;
	using result = ratio_add<r1, r2>::type;
	cout << "4) " << result::num << "/" << result::den << endl;

	// 두 유리수를 비교한다.
	using res = ratio_less<r2, r1>;
	cout << "5) " << boolalpha << res::value << endl;

	return 0;
}
