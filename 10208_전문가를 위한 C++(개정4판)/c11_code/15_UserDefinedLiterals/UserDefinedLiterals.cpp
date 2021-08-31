#include <cstddef>
#include <complex>

// Cooked _i literal
std::complex<long double> operator"" _i(long double d)
{  
	return std::complex<long double>(0, d);  
}

// �� _i ���ͷ�
//std::complex<long double> operator"" _i(const char* p)
//{
//    // ���� �ڵ� ����. C-��Ÿ�� ��Ʈ���� �Ľ��ϰ� ���Ҽ��� ��ȯ�ؾ� �Ѵ�.
//}


// ���� ��� _s ���ͷ�
std::string operator"" _s(const char* str, size_t len)
{
	return std::string(str, len);
}

int main()
{
	// ���� ��� _i ���ͷ�
	std::complex<long double> c1 = 9.634_i;
	auto c2 = 1.23_i;         // c2 Ÿ���� std::complex<long double>

	// ���� ��� _s ���ͷ�
	std::string str1 = "Hello World"_s;
	auto str2 = "Hello World"_s;   // str2�� Ÿ���� std::string
	auto str3 = "Hello World";     // str3�� Ÿ���� const char*;

	return 0;
}
