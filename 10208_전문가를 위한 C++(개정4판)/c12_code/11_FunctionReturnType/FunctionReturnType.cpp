#include <iostream>

// C++14: �Լ��� ���� Ÿ�� �ڵ� ���� ��� ����
template<typename T1, typename T2>
auto add(const T1& t1, const T2& t2)
{
	return t1 + t2;
}

// C++14: decltype(auto) ��� ����
//template<typename T1, typename T2>
//decltype(auto) add(const T1& t1, const T2& t2)
//{
//	return t1 + t2;
//}

// ��ü �Լ� ���� ����
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
