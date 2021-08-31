#include "namespaces.h"

using namespace mycode;

int main()
{
	mycode::foo();	// mycode 네임스페이스에 있는 "foo" 함수를 호출한다.
	foo();			// mycode::foo(); 와 같다.
	return 0;
}
