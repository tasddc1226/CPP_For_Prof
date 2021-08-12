#include <iostream>
#include <stdexcept>
#include <exception>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

int main()
{
	Database employeeDB;

	bool done = false;
	while (!done) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			done = true;
			break;
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayAll();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayFormer();
			break;
		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}

	return 0;
}

int displayMenu()
{
	// 화면에 메뉴를 출력 -> 사용자의 입력을 받음.
	// 숫자를 요청하면 숫자를 입력한다고 가정.
	// 잘못된 입력이 들어오면 예외 처리
	int selection;

	cout << endl;
	cout << "Employee Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Hire a new employee" << endl;
	cout << "2) Fire an employee" << endl;
	cout << "3) Promote an employee" << endl;
	cout << "4) List all employees" << endl;
	cout << "5) List all current employees" << endl;
	cout << "6) List all former employees" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "---> ";

	cin >> selection;

	return selection;
}

void doHire(Database& db)
{
	// 신입직원의 이름을 입력받아 DB에 그 직원에 대한 정보 추가요청
	string firstName;
	string lastName;

	cout << "First name? ";
	cin >> firstName;
	cout << "Last name? ";
	cin >> lastName;

	db.addEmployee(firstName, lastName);
}

void doFire(Database& db)
{
	int employeeNumber;

	cout << "Employee number? ";
	cin >> employeeNumber;

	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.fire();
		cout << "Employee " << employeeNumber << " terminated." << endl;
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to terminate employee: " << exception.what() << endl;
	}
}

void doPromote(Database& db)
{
	int employeeNumber;
	int raiseAmount;

	cout << "Employee number? ";
	cin >> employeeNumber;
	cout << "How much of a raise? ";
	cin >> raiseAmount;

	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to promote employee: " << exception.what() << endl;
	}
}

void doDemote(Database& db) {
	int employeeNumber;
	int demeritAmount;

	cout << "Employee number? ";
	cin >> employeeNumber;
	cout << "How much of a demerit? ";
	cin >> demeritAmount;

	try
	{
		Employee& emp = db.getEmployee(employeeNumber);
		emp.demote(demeritAmount);
	}
	catch (const std::logic_error& exception)
	{
		cerr << "Unable to demote employee. " << exception.what() << endl;

	}

}
