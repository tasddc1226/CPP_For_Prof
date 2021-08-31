#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 3> myArray{ 11, 22, 33 };
	cout << std::get<1>(myArray) << endl;
	// cout << std::get<10>(myArray) << endl;  // 컴파일 에러가 발생한다.
}