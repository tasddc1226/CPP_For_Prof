#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// courseStudents�� list�� ���� vector��. �̶� list�� �� ������ �ǹ��Ѵ�.
// ��, �� ������ ��ϵ� �л��� list�� ���ҷ� ��� �ִ�. ���ĵ� ���´� �ƴϴ�.
//
// droppedStudents�� ��ϱ��� ���� �ʾ� �ش� ������ ��ϵ��� ���� �л��� ���� list��.
//
// �� �Լ��� ��� ������ ���� ��ϵ�(����� ��ҵ��� ����) �л��� ���� list�� �����Ѵ�.
list<string> getTotalEnrollment(const vector<list<string>>& courseStudents,
								const list<string>& droppedStudents)
{
	list<string> allStudents;

	// �� ������ ���� ����Ʈ�� ��� ������ ����Ʈ�� ��ģ��.
	for (auto& lst : courseStudents) {
		allStudents.insert(cend(allStudents), cbegin(lst), cend(lst));
	}

	// ������ ����Ʈ�� �����Ѵ�.
	allStudents.sort();

	// �̸��� �ߺ��� �л�(���� ������ ���ÿ� ��ϵ� �л�)�� �����Ѵ�.
	allStudents.unique();

	// ����� ��ҵ� ����Ʈ�� ���� �л��� �����Ѵ�.
	// droppedStudent ����Ʈ�� ���� �ݺ��ϸ鼭
	// ���� ���� �л��� ���� ������ ����Ʈ�� remove()�� ȣ���Ѵ�.
	for (auto& str : droppedStudents) {
		allStudents.remove(str);
	}

	// �۾� ��!
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
