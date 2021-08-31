#include <iostream>
#include <string>
#include "SimpleTemplate.h" 

using namespace std;

int main()
{
	// ������ ���Ѵ�.
	int i = 7;
	SimpleTemplate<int> intWrapper(i);
	i = 2;
	cout << "wrapped value is " << intWrapper.get() << endl;

	// ��Ʈ���� ���Ѵ�.
	string str = "test";
	SimpleTemplate<string> stringWrapper(str);
	str += "!";
	cout << "wrapped value is " << stringWrapper.get() << endl;

	return 0;
}
