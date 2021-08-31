#include <string>

void mysteryFunction(const std::string* someString)
{
    *someString = "Test";  // 컴파일 에러 
}

int main()
{
    std::string myString = "The string";
    mysteryFunction(&myString);
    return 0;
}
