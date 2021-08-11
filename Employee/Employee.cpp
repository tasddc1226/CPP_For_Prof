// Employee.cpp

#include <iostream>
#include "Employee.h"

using namespace std;

namespace Records {
	// 성, 이름을 받아 각각의 값을 해당 데이터 맴버에 설정.
	Employee::Employee(const std::string& firstName, const std::string& lastName)
		: mFirstName(firstName)
		, mLastName(lastName)
	{
	}

	// 인수로 전달된 값을 의미에 맞게 바꿔서 setSalary 메서드로 전달.
	void Employee::promote(int raiseAmount)
	{
		setSalary(getSalary() + raiseAmount);
	}

	void Employee::demote(int demeritAmount)
	{
		setSalary(getSalary() - demeritAmount);
	}

	// mHired 변수 설정하는 고용, 해고 메서드
	void Employee::hire()
	{
		mHired = true;
	}

	void Employee::fire()
	{
		mHired = false;
	}

	// 현재 직원에 대한 정보를 콘솔 출력.
	void Employee::display() const
	{
		cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
		cout << "-------------------------" << endl;
		cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
		cout << "Employee Number: " << getEmployeeNumber() << endl;
		cout << "Salary: $" << getSalary() << endl;
		cout << endl;
	}

	// getter & setter
	void Employee::setFirstName(const string& firstName)
	{
		mFirstName = firstName;
	}

	const string& Employee::getFirstName() const
	{
		return mFirstName;
	}

	void Employee::setLastName(const string& lastName)
	{
		mLastName = lastName;
	}

	const string& Employee::getLastName() const
	{
		return mLastName;
	}

	void Employee::setEmployeeNumber(int employeeNumber)
	{
		mEmployeeNumber = employeeNumber;
	}

	int Employee::getEmployeeNumber() const
	{
		return mEmployeeNumber;
	}

	void Employee::setSalary(int salary)
	{
		mSalary = salary;
	}

	int Employee::getSalary() const
	{
		return mSalary;
	}

	bool Employee::isHired() const
	{
		return mHired;
	}

}
