#include <cstddef>
#include <complex>

// Cooked _i literal
std::complex<long double> operator"" _i(long double d)
{  
	return std::complex<long double>(0, d);  
}

// 로 _i 리터럴
//std::complex<long double> operator"" _i(const char* p)
//{
//    // 구현 코드 생략. C-스타일 스트링을 파싱하고 복소수로 변환해야 한다.
//}


// 가공 모드 _s 리터럴
std::string operator"" _s(const char* str, size_t len)
{
	return std::string(str, len);
}

int main()
{
	// 가공 모드 _i 리터럴
	std::complex<long double> c1 = 9.634_i;
	auto c2 = 1.23_i;         // c2 타입은 std::complex<long double>

	// 가공 모드 _s 리터럴
	std::string str1 = "Hello World"_s;
	auto str2 = "Hello World"_s;   // str2의 타입은 std::string
	auto str3 = "Hello World";     // str3의 타입은 const char*;

	return 0;
}
