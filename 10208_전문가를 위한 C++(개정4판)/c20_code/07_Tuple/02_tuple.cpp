#include <iostream>
#include <string>
#include <tuple> 
#include <functional>  // for ref() and cref()
#include <typeinfo>

using namespace std;

int main()
{
	using MyTuple = tuple<int, string, bool>;
	MyTuple t1(16, "Test", true);
	cout << "t1 = (" << get<0>(t1) << ", " << get<1>(t1)
		 << ", " << get<2>(t1) << ")" << endl;
	cout << "Type of get<1>(t1) = " << typeid(get<1>(t1)).name() << endl;
	cout << "String = " << get<string>(t1) << endl;
	cout << "Tuple Size = " << tuple_size<MyTuple>::value << endl;
	cout << "Tuple Size = " << tuple_size<decltype(t1)>::value << endl;

	double d = 3.14;
	string str1 = "Test";
	// t2의 타입은 tuple<int, double&, const double&, string&>
	auto t2 = make_tuple(16, ref(d), cref(d), ref(str1));
	// C++17 생성자에 대한 템플릿 인수 추론 기능을 적용한 버전
	// std::tuple t2(16, ref(d), cref(d), ref(str1));

	cout << "d = " << d << endl;
	get<1>(t2) *= 2;
	//get<2>(t2) *= 2;
	cout << "d = " << d << endl;

	return 0;
}