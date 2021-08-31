#include <string>

using namespace std;

class FunctionObject
{
public:
	int operator() (int param);	// 함수 호출 연산자
	void operator() (string_view /*str*/) {}
	int doSquare(int param);		// 일반 메서드
};

// 오버로딩한 함수 호출 연산자의 구현 코드
int FunctionObject::operator() (int param)
{
	return doSquare(param);
}

// 일반 메서드의 구현 코드
int FunctionObject::doSquare(int param)
{
	return param * param;
}

int main()
{
	int x = 3, xSquared, xSquaredAgain;
	FunctionObject square;

	xSquared = square(x);				// 함수 호출 연산자를 호출한다.
	xSquaredAgain = square.doSquare(x);	// 일반 메서드를 호출한다.

	return 0;
}

