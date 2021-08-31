#include <string>
#include <iostream>

void printString(const std::string& myString)
{
	std::cout << myString << std::endl;
}

int main()
{
	std::string someString = "Hello World";
	printString(someString);
	printString("Hello World");  // 리터럴을 전달해도 된다.
	return 0;
}
