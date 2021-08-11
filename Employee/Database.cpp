// Database.cpp

#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace Records {
	// 새로운 Employee 객체 생성 후 vector에 추가
	Employee& Database::addEmployee(const string& firstName, const string& lastName)
	{
		Employee theEmployee(firstName, lastName);
		// 다음 직원이 새로운 번호를 받기위해 1 증가
		theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
		theEmployee.hire();
		mEmployees.push_back(theEmployee);

		return mEmployees[mEmployees.size() - 1];
	}

	// 범위기반 for문을 사용하여 mEmployees에 있는 모든 직원을 돌면서
	// 전달된 직원번호와 같은 직원을 찾는다.
	Employee& Database::getEmployee(int employeeNumber)
	{
		for (auto& employee : mEmployees) {
			if (employee.getEmployeeNumber() == employeeNumber) {
				return employee;
			}
		}
		// 없다면 예외 발생
		throw logic_error("No employee found.");
	}

	// 직원의 성, 이름을 받아와 해당 직원이 있는지 조회
	Employee& Database::getEmployee(const string& firstName, const string& lastName)
	{
		for (auto& employee : mEmployees) {
			if (employee.getFirstName() == firstName &&
				employee.getLastName() == lastName) {
					return employee;
			}
		}
		// 없다면 예외 발생
		throw logic_error("No employee found.");
	}

	// 모든 직원에 대하여 Loop를 돌면서 일정 조건에 만족하는
	// 직원의 정보를 콘솔에 출력
	void Database::displayAll() const
	{
		for (const auto& employee : mEmployees) {
			employee.display();
		}
	}

	void Database::displayCurrent() const
	{
		for (const auto& employee : mEmployees) {
			if (employee.isHired())
				employee.display();
		}
	}

	void Database::displayFormer() const
	{
		for (const auto& employee : mEmployees) {
			if (!employee.isHired())
				employee.display();
		}
	}

}
