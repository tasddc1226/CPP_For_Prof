#include <iostream>
#include "Employee.h"

using namespace std;
using namespace Records;

int main()
{
	Employee employee;
	
	// ���� ��Ÿ��:
	//int (Employee::*methodPtr) () const = &Employee::getSalary;

	// Ÿ�� �ٸ�� ���:
	//using PtrToGet = int (Employee::*) () const;
	//PtrToGet methodPtr = &Employee::getSalary;

	// auto ���:
	auto methodPtr = &Employee::getSalary;

	cout << (employee.*methodPtr)() << endl;

	return 0;
}