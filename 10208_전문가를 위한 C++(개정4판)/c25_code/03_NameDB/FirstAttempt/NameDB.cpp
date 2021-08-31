#include "NameDB.h"
#include <stdexcept>
#include <fstream>

using namespace std;

// 파일에서 읽은 이름을 데이터베이스에 저장한다.
// 데이터베이스는 이름/수 쌍을 담는 vector로 구성한다.
// 각 항목마다 이름과 그 이름이 원본 데이터에 나온 횟수를 담고 있다.
NameDB::NameDB(string_view nameFile)
{
	// 파일을 열고 에러가 발생했는지 확인한다.
	ifstream inputFile(nameFile.data());
	if (!inputFile) {
		throw invalid_argument("Unable to open file");
	}

	// 이름을 한 번에 하나씩 읽는다.
	string name;
	while (inputFile >> name) {
		// 주어진 이름이 데이터베이스에 이미 있는지 확인한다.
		if (nameExists(name)) {
			// 주어진 이름이 데이터베이스에 있다면 횟수만 증가한다.
			incrementNameCount(name);
		} else {
			// 데이터베이스에 이름이 없다면 새로 추가하고 횟수를 1로 지정한다.
			addNewName(name);
		}
	}
}

// 데이터베이스에 이름이 있다면 true를 리턴하고, 그렇지 않다면 false를 리턴한다.
bool NameDB::nameExists(string_view name) const
{
	// 이름을 담은 벡터에 대해 루프를 돌면서 주어진 이름을 검색한다.
	for (auto& entry : mNames) {
		if (entry.first == name) {
			return true;
		}
	}
	return false;
}

// 선행 조건(Precondition): 이름을 담은 벡터에 주어진 이름이 존재해야 한다.
// 후행 조건(Postcondition): 그 이름에 대한 횟수를 하나 증가시킨다.
void NameDB::incrementNameCount(string_view name)
{
	for (auto& entry : mNames) {
		if (entry.first == name) {
			entry.second++;
			return;
		}
	}
}

// 데이터베이스에 새 이름을 추가한다.
void NameDB::addNewName(string_view name)
{
	mNames.push_back(make_pair(name.data(), 1));
}

// 이름의 순위를 리턴한다.
// 먼저 주어진 이름을 가진 신생아 수를 조회한다.
// 그러고 나서 모든 이름에 대해 반복문을 돌면서
// 주어진 이름보다 순위가 높은 이름의 수를 세고 순위를 리턴한다.
int NameDB::getNameRank(string_view name) const
{
	// getAbsoluteNumber() 메서드로 처리한다.
	int num = getAbsoluteNumber(name);

	// 이름을 찾았는지 확인한다.
	if (num == -1) {
		return -1;
	}

	// 주어진 이름보다 수가 많은 이름을 벡터에서 모두 찾는다.
	// 주어진 이름보다 순위가 높은 이름이 없다면 그 이름을 1위로 만든다.
	// 주어진 이름보다 빈도가 낮은 이름의 순위를 1씩 감소한다.
	int rank = 1;
	for (auto& entry : mNames) {
		if (entry.second > num) {
			rank++;
		}
	}

	return rank;
}

// 주어진 이름의 수를 리턴한다.
int NameDB::getAbsoluteNumber(string_view name) const
{
	for (auto& entry : mNames) {
		if (entry.first == name) {
			return entry.second;
		}
	}
	return -1;
}
