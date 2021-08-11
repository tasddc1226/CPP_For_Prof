// Employee.h
#pragma once 

#include <string>

// Records라는 네임스페이스에 속하도록 선언
namespace Records {
	// 신입직원의 기본 급여 정의
	const int kDefaultStartingSalary = 30000; 

	class Employee
	{
	public:
		// default 생성자 & 성, 이름을 받는 생성자
		Employee() = default;
		Employee(const std::string& firstName, const std::string& lastName);

		// 정수 type의 매개변수를 받음. 기본값이 정해져 있어서 매개변수가 없다면 default값으로
		void promote(int raiseAmount = 1000);
		void demote(int demeritAmount = 1000);
		void hire(); // 직원 고용
		void fire(); // 직원 해고.
		void display() const;// 직원 정보 콘솔 출력

		// getter & setter
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setEmployeeNumber(int employeeNumber);
		int getEmployeeNumber() const;

		void setSalary(int newSalary);
		int getSalary() const;

		bool isHired() const;


	// 다른 코드에서 수정하지 못하도록 private로 데이터 맴버 선언
	private:
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber = -1;
		int mSalary = kDefaultStartingSalary;
		bool mHired = false;
	};
}

