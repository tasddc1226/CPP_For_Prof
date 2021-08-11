#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records{
    // 직원번호의 시작값 상수로 지정
    const int kFirstEmployeeNumber = 1000;

    
    class Database{
        public:
            // 성, 이름을 입력 => 직원에 대한 정보 추가 가능
            Employee& addEmployee(const std::string& firstName, const std::string& lastName);
            // 직원 번호로 직원 조회
            Employee& getEmployee(int employeeNumber);
            // 성, 이름으로 직원 조회
            Employee& getEmployee(const std::string& firstName, const std::string& lastName);

            // 모든 직원에 대한 정보, 현재 재직 중인 직원 정보, 퇴사한 직원 정보 출력 메서드
            void displayAll() const;
            void displayCurrent() const;
            void displayFormer() const;

        private:
            std::vector<Employee> mEmployees;
            int mNextEmployeeNumber = kFirstEmployeeNumber;
    };
}