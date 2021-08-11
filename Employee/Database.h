// Database.h
// std::vector 클래스를 이용하여 Employee 객체 저장
#pragma once

#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records {
	// 신입 직원에 대한 직원번호는 DB 내부에서 자동 할당을 위해 시작값을 상수로 정의
	const int kFirstEmployeeNumber = 1000;

	class Database
	{
	public:
		// 성, 이름으로 신입 직원 추가
		Employee& addEmployee(const std::string& firstName,
							  const std::string& lastName);
		// 직원번호로 직원 조회
		Employee& getEmployee(int employeeNumber);
		// 성, 이름으로 직원 조회
		Employee& getEmployee(const std::string& firstName,
							  const std::string& lastName);

		// 모든 직원 정보를 출력
		void displayAll() const;
		// 현재 재직중인 직원 정보 출력
		void displayCurrent() const;
		// 퇴사한 직원 정보 출력
		void displayFormer() const;

	private:
		// mEmployees는 Employee 객체를 가지고 있는 배열
		std::vector<Employee> mEmployees;
		// 신입직원에 할당된 직원 번호를 기록하며 상수로 초기화
		int mNextEmployeeNumber = kFirstEmployeeNumber;
	};
}
