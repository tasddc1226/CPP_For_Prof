#include <iostream>
#include <string>
#include <tuple> 

using namespace std;

int main()
{
	tuple<int, string, bool> t1(16, "Test", true);
	//tuple t1(16, "Test"s, true); // C++17 생성자에 대한 템플릿 인수 추론 기능 적용
	auto[i, str, b] = t1;
	cout << "Decomposed: i = " << i << ", str = \"" << str << "\", b = " << b << endl;


	return 0;
}