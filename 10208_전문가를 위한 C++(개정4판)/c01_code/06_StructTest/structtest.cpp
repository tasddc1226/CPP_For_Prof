#include <iostream>
#include "employeestruct.h"

using namespace std;

int main()
{
	// ������ �����ϰ� �Ӽ��� �����Ѵ�.
	Employee anEmployee;

	anEmployee.firstInitial = 'M';
	anEmployee.lastInitial = 'G';
	anEmployee.employeeNumber = 42;
	anEmployee.salary = 80000;

	// ������ ���� �Ӽ��� ����Ѵ�.
	cout << "Employee: " << anEmployee.firstInitial << 
							anEmployee.lastInitial << endl;
	cout << "Number: " << anEmployee.employeeNumber << endl;
	cout << "Salary: $" << anEmployee.salary << endl;

	return 0;
}
