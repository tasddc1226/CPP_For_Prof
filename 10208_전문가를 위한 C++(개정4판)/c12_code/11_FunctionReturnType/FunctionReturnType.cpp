#include <iostream>

// C++14: 함수의 리턴 타입 자동 유추 기능 적용
template<typename T1, typename T2>
auto add(const T1& t1, const T2& t2)
{
	return t1 + t2;
}

// C++14: decltype(auto) 기능 적용
//template<typename T1, typename T2>
//decltype(auto) add(const T1& t1, const T2& t2)
//{
//	return t1 + t2;
//}

// 대체 함수 구문 적용
//template<typename T1, typename T2>
//auto add(const T1& t1, const T2& t2) -> decltype(t1 + t2)
//{
//	return t1 + t2;
//}

int main()
{
	std::cout << add(2, 4) << std::endl;

	return 0;
}
