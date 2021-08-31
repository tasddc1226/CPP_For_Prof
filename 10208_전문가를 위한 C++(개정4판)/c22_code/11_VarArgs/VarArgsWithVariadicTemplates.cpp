#include <iostream>
#include <string>
#include <string_view>

using namespace std;

void handleValue(int value)
{
	cout << "Integer: " << value << endl;
}
void handleValue(double value)
{
	cout << "Double: " << value << endl;
}
void handleValue(string_view value)
{
	cout << "String: " << value << endl;
}



// 값 전달 방식을 이용하는 첫 번째 버전
void processValues()	// 베이스 케이스
{
	// 베이스 케이스에 대해서 특별히 할 일이 없다.
}

template<typename T1, typename... Tn>
void processValues(T1 arg1, Tn... args)
{
	handleValue(arg1);
	processValues(args...);
}



// 우측값 레퍼런스 전달 방식을 이용하는 두 번째 버전
void processValuesRValueRefs()	// 베이스 케이스
{
	// 베이스 케이스에 대해 특별히 할 일이 없다.
}

template<typename T1, typename... Tn>
void processValuesRValueRefs(T1&& arg1, Tn&&... args)
{
	handleValue(std::forward<T1>(arg1));
	processValuesRValueRefs(std::forward<Tn>(args)...);
}



int main()
{
	processValues(1, 2, 3.56, "test", 1.1f);
	cout << endl;
	processValuesRValueRefs(1, 2, 3.56, "test", 1.1f);

	return 0;
}
