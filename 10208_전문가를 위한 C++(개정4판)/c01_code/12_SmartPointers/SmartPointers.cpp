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
		// �迭�� unique_ptr�� �����Ѵ�.
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
		// �迭�� shared_ptr�� �����Ѵ�. (C++17)
		shared_ptr<Employee[]> employees(new Employee[10]);
		cout << "Salary: " << employees[0].salary << endl;
	}
}
