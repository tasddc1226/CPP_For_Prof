#include <iostream>
#include <functional>

using namespace std;

function<int(void)> multiplyBy2Lambda(int x)
{
	return [x]{ return 2 * x; };
}

// 함수 리턴 타입 추론을 적용할 경우
//auto multiplyBy2Lambda(int x)
//{
//	return [x]{ return 2 * x; };
//}

int main()
{
	//function<int(void)> fn = multiplyBy2Lambda(5);
	//cout << fn() << endl;

	auto fn = multiplyBy2Lambda(5);
	cout << fn() << endl;


	return 0;
}