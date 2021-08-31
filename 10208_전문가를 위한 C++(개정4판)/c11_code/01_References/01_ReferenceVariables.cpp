#include <string>

std::string getString()
{
	return "Hello world!";
}

int main()
{
	int x = 3, y = 4, z = 5;
	int& xRef = x;
	xRef = 10;
	//  int& emptyRef; // 컴파일 에러!

	//  int& unnamedRef1 = 5;   // 컴파일 에러!
	const int& unnamedRef2 = 5; // 정상 실행

	//  std::string& string1 = getString();   // 컴파일 에러!
	const std::string& string2 = getString(); // 정상 실행

	xRef = y; // x 값을 4로 바꾼다. xRef가 y를 가리키게 되지는 않는다.

	int& zRef = z;
	zRef = xRef; // 레퍼런스가 아닌 값을 대입한다.

	int* intP;
	int*& ptrRef = intP;
	ptrRef = new int;
	*ptrRef = 5;

	int* xPtr = &xRef; // 레퍼런스의 주소는 값에 대한 포인터다.
	*xPtr = 100;

	return 0;
}
