#include <iostream>
#include "Employee.h"

using namespace std;

namespace Records {
    
    // 생성자로 성과 이름에 대한 인수를 받아 각각의 값을 해당 데이터 맴버에 설정
    Employee::Employee(const std::string& firstName, const std::string& lastName)
     : mFirstName(firstName), mLastName(lastName)
    {
    }

    // promote & demote는 단순히 인수로 전달된 값을 각자의 의미에 맞게 바꿔서
    // setSalary 메서드에 전달.
    void Employee::promote(int raiseAmount)
	{
		setSalary(getSalary() + raiseAmount);
	}

	void Employee::demote(int demeritAmount)
	{
		setSalary(getSalary() - demeritAmount);
	}

    // hire & fire는 mHired 데이터 맴버를 설정
	void Employee::hire()
	{
		mHired = true;
	}

	void Employee::fire()
	{
		mHired = false;
	}

    // display는 현재 직원에 대한 정보를 console에 출력 스트림으로 화면에 표시
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
