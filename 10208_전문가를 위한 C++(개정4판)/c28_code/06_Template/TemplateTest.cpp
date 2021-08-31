#include <iostream>
#include <string>
#include "SimpleTemplate.h" 

using namespace std;

int main()
{
	// 정수를 감싼다.
	int i = 7;
	SimpleTemplate<int> intWrapper(i);
	i = 2;
	cout << "wrapped value is " << intWrapper.get() << endl;

	// 스트링을 감싼다.
	string str = "test";
	SimpleTemplate<string> stringWrapper(str);
	str += "!";
	cout << "wrapped value is " << stringWrapper.get() << endl;

	return 0;
}
