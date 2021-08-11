#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;
using namespace Records;

namespace Records {
    Employee& Database::addEmployee(const string& firstName, const string& lastName){
        Employee theEmployee(firstName, lastName);
        theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
        theEmployee.hire();
        mEmployees.push_back(theEmployee);
        return mEmployees[mEmployees.size() - 1];
    }

    Employee& Database::getEmployee(int employeeNumber){
        for (auto& employee : mEmployees){
            if (employee.getEmployeeNumber() == employeeNumber){
                return employee;
            }
        }
        throw logic_error("No emp found.");
    }

    void Database::displayAll() const{
        for (const auto& employee : mEmployees){
            if (employee.isHired())
                employee.display();
        }
    }
}

// DatabaseTest.cpp

int main() {
    Database myDB;
    Employee& emp1 = myDB.addEmployee("Gray", "Wallis");
    emp1.fire();

    Employee& emp2 = myDB.addEmployee("Marc", "white");
    emp2.setSalary(100000);

    Employee& emp3 = myDB.addEmployee("John", "Smith");
    emp3.setSalary(200000);
    emp3.promote();

    cout << "All Employees: " << endl << endl;
    myDB.displayAll();

    cout << endl << "current Employees: " << endl << endl;
    myDB.displayCurrent();

    cout << endl << "former Employees: " << endl << endl;
    myDB.displayFormer();

}