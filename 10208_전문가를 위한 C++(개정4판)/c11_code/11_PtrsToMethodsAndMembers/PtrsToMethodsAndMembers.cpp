#include <iostream>
#include "Employee.h"

using namespace std;
using namespace Records;

int main()
{
	Employee employee;
	
	// 예전 스타일:
	//int (Employee::*methodPtr) () const = &Employee::getSalary;

	// 타입 앨리어스 사용:
	//using PtrToGet = int (Employee::*) () const;
	//PtrToGet methodPtr = &Employee::getSalary;

	// auto 사용:
	auto methodPtr = &Employee::getSalary;

	cout << (employee.*methodPtr)() << endl;

	return 0;
}