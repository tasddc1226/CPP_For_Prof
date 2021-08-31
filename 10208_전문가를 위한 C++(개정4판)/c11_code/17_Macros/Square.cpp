#include <iostream>
using namespace std;

#define SQUARE(x) ((x) * (x)) // 매크로 정의 끝에는 세미콜론을 붙이지 않는다.
//#define SQUARE(x) (x * x)

int main()
{
	cout << SQUARE(5) << endl;
	cout << SQUARE(2 + 3) << endl;

	return 0;
}
