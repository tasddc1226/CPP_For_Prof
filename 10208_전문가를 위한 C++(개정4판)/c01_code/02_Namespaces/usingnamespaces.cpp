#include "namespaces.h"

using namespace mycode;

int main()
{
	mycode::foo();	// mycode ���ӽ����̽��� �ִ� "foo" �Լ��� ȣ���Ѵ�.
	foo();			// mycode::foo(); �� ����.
	return 0;
}
