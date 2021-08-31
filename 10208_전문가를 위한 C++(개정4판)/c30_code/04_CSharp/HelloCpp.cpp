#include <iostream>

using namespace std;

extern "C"
{
    __declspec(dllexport) int FunctionInDLL(const wchar_t* p)
    {
        wcout << L"The following string was received by C++:\n    '";
        wcout << p << L"'" << endl;
        return 42;    // 값을 리턴한다...
    }
}
