#include <iostream>
#include "employeestruct.h"

using namespace std;

int main()
{
	// 직원을 생성하고 속성을 설정한다.
	Employee anEmployee;

	anEmployee.firstInitial = 'M';
	anEmployee.lastInitial = 'G';
	anEmployee.employeeNumber = 42;
	anEmployee.salary = 80000;

	// 직원에 대한 속성을 출력한다.
	cout << "Employee: " << anEmployee.firstInitial << 
							anEmployee.lastInitial << endl;
	cout << "Number: " << anEmployee.employeeNumber << endl;
	cout << "Salary: $" << anEmployee.salary << endl;

	return 0;
}
