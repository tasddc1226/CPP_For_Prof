#include <string>

void mysteryFunction(const std::string* someString)
{
    *someString = "Test";  // ������ ���� 
}

int main()
{
    std::string myString = "The string";
    mysteryFunction(&myString);
    return 0;
}
