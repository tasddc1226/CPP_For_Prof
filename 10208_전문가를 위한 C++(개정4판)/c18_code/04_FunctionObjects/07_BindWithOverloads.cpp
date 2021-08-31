#include <functional>

using namespace std;

void overloaded(int /* num */) {}
void overloaded(float /* f */) {}

int main()
{
	// 오버로딩된 함수에 바인딩하기
	//auto f3 = bind(overloaded, placeholders::_1);					// ERROR
	auto f4 = bind((void(*)(float))overloaded, placeholders::_1);	// OK
	
	return 0;
}

