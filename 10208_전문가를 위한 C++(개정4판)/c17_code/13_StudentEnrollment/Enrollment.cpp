#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// courseStudents는 list에 대한 vector다. 이때 list는 각 과정을 의미한다.
// 즉, 각 과정에 등록된 학생을 list의 원소로 담고 있다. 정렬된 상태는 아니다.
//
// droppedStudents는 등록금을 내지 않아 해당 과정에 등록되지 않은 학생에 대한 list다.
//
// 이 함수는 모든 과정에 현재 등록된(등록이 취소되지 않은) 학생에 대한 list를 리턴한다.
list<string> getTotalEnrollment(const vector<list<string>>& courseStudents,
								const list<string>& droppedStudents)
{
	list<string> allStudents;

	// 각 과정에 대한 리스트를 모두 마스터 리스트에 합친다.
	for (auto& lst : courseStudents) {
		allStudents.insert(cend(allStudents), cbegin(lst), cend(lst));
	}

	// 마스터 리스트를 정렬한다.
	allStudents.sort();

	// 이름이 중복된 학생(여러 과정에 동시에 등록된 학생)을 제거한다.
	allStudents.unique();

	// 등록이 취소된 리스트에 속한 학생을 제거한다.
	// droppedStudent 리스트에 대해 반복하면서
	// 여기 나온 학생에 대해 마스터 리스트의 remove()를 호출한다.
	for (auto& str : droppedStudents) {
		allStudents.remove(str);
	}

	// 작업 끝!
	return allStudents;
}

list<string> readStudentList(ifstream& istr)
{
	list<string> students;
	string name;
	while (getline(istr, name)) {
		cout << "Read name " << name << endl;
		students.push_back(name);
	}
	return students;
}

vector<list<string>> readCourseLists()
{
	vector<list<string>> lists;
	for (int i = 1;; i++) {
		ostringstream ostr;
		ostr << "course" << i << ".txt";

		ifstream istr(ostr.str().c_str());
		if (!istr) {
			cout << "Failed to open " << ostr.str() << endl;
			break;
		}
		lists.push_back(readStudentList(istr));
	}
	return lists;
}

list<string> readDroppedStudents()
{
	ifstream istr("dropped.txt");
	return readStudentList(istr);
}

int main()
{
	vector<list<string>> courseStudents = readCourseLists();
	list<string> droppedStudents = readDroppedStudents();

	list<string> finalList = getTotalEnrollment(courseStudents, droppedStudents);

	for (const auto& name : finalList) {
		cout << name << endl;
	}

	return 0;
}
