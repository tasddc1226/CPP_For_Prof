#include <iostream>
#include <string>

using namespace std;

void helper(std::string&& message)
{
}

// 좌측값 레퍼런스 매개변수
void handleMessage(std::string& message)
{
	cout << "handleMessage with lvalue reference: " << message << endl;
}

// 우측값 레퍼런스 매개변수
void handleMessage(std::string&& message)
{
	cout << "handleMessage with rvalue reference: " << message << endl;
	helper(std::move(message));
}

int main()
{
	std::string a = "Hello ";
	std::string b = "World";

	// 이름 있는 변수를 처리한다.
	handleMessage(a);             // handleMessage(string& value)를 호출한다.

	// 표현식을 처리한다.
	handleMessage(a + b);         // handleMessage(string&& value)를 호출한다.

	// 리터럴을 처리한다.
	handleMessage("Hello World"); // handleMessage(string&& value)을 호출한다.

	// 이름 있는 변수를 처리하고 우측값 레퍼런스 메서드를 사용하도록 설정한다.
	handleMessage(std::move(b));  // handleMessage(string&& value)를 호출한다.

	return 0;
}
