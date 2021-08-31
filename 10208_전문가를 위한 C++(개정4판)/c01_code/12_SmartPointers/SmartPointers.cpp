#include <iostream>
#include <memory>

using namespace std;

struct Employee {
	char firstInitial = 'M';
	char lastInitial = 'G';
	int  employeeNumber = 42;
	int  salary = 80'000;
};

int main()
{
	{
		// unique_ptr
		auto anEmployee = make_unique<Employee>();
		if (anEmployee) {
			cout << "Salary: " << anEmployee->salary << endl;
		}
	}

	{
		// 배열을 unique_ptr로 저장한다.
		auto employees = make_unique<Employee[]>(10);
		cout << "Salary: " << employees[0].salary << endl;
	}

	{
		// shared_ptr
		auto anEmployee = make_shared<Employee>();
		if (anEmployee) {
			cout << "Salary: " << anEmployee->salary << endl;
		}
	}

	{
		// 배열을 shared_ptr로 저장한다. (C++17)
		shared_ptr<Employee[]> employees(new Employee[10]);
		cout << "Salary: " << employees[0].salary << endl;
	}
}
