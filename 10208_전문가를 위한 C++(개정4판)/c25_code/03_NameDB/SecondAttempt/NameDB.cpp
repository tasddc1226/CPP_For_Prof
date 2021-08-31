#include "NameDB.h"
#include <stdexcept>
#include <fstream>

using namespace std;

// 파일에서 읽은 이름을 데이터베이스에 저장한다.
// 이 데이터베이스는 이름과 빈도에 대한 map으로 구성한다.
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
		if (!nameExistsAndIncrement(name)) {
			// 주어진 이름이 데이터베이스에 이미 있다면 갯수를 하나 증가시키고 이 블록을 건너뛴다.
			// 이 블록에 들어왔다면 데이터베이스에 없는 이름이란 뜻이므로
			// 이름을 추가하고 갯수를 하나 증가시킨다.
			addNewName(name);
		}
	}
}

// 데이터베이스에 이름이 있다면 true를 리턴하고, 그렇지 않다면 false를 리턴한다.
// 데이터베이스에서 이름을 발견했다면 갯수를 하나 증가시킨다.
bool NameDB::nameExistsAndIncrement(string_view name)
{
	// 주어진 이름을 맵에서 찾는다.
	auto res = mNames.find(name.data());
	if (res != end(mNames)) {
		res->second++;
		return true;
	}
	return false;
}

// 데이터베이스에 이름을 새로 추가한다.
void NameDB::addNewName(string_view name)
{
	mNames[name.data()] = 1;
}

// 주어진 이름의 순위를 리턴한다.
// 먼저 주어진 이름을 가진 아기의 수를 구한다.
// 그러고 나서 모든 이름에 대해 루프를 돌면서 지정한 이름보다 순위가 높은 이름의 갯수를 모두 센다.
// 마지막으로 그 갯수를 순위로 리턴한다.
int NameDB::getNameRank(string_view name) const
{
	int num = getAbsoluteNumber(name);

	// 이름을 찾았는지 확인한다.
	if (num == -1) {
		return -1;
	}

	// 맵에 있는 이름 중에서 지정한 이름보다 순위가 높은 이름의 갯수를 센다.
	// 그런 이름이 없다면 지정한 이름이 1위다. 
	// 지정한 이름보다 높은 순위의 이름이 있을 때마다 지정한 이름의 순위를 1씩 감소한다.
	int rank = 1;
	for (auto& entry : mNames) {
		if (entry.second > num) {
			rank++;
		}
	}

	return rank;
}

// 지정한 이름의 갯수를 리턴한다.
int NameDB::getAbsoluteNumber(string_view name) const
{
	auto res = mNames.find(name.data());
	if (res != end(mNames)) {
		return res->second;
	}

	return -1;
}
