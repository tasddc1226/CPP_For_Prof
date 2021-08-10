// Employee.cpp Test 하기 위함.
// 모두 복사해서 Employee.cpp 파일 아래에 붙여넣고 Employee.cpp 컴파일 후 ./a.out 실행

#include <iostream>
#include "Employee.h"

using namespace std;
using namespace Records;

int main(){
    cout << "Testing the Employee class." << endl;
    Employee emp;
    emp.setFirstName("Su Young");
    emp.setLastName("Yang");
    emp.setEmployeeNumber(99);
    emp.setSalary(50000);
    emp.promote();
    emp.promote(50);
    emp.hire();
    emp.display();
    return 0;
}