#include "NameDB.h"
#include <stdexcept>
#include <fstream>

using namespace std;

// ���Ͽ��� ���� �̸��� �����ͺ��̽��� �����Ѵ�.
// �� �����ͺ��̽��� �̸��� �󵵿� ���� map���� �����Ѵ�.
NameDB::NameDB(string_view nameFile)
{
	// ������ ���� ������ �߻��ߴ��� Ȯ���Ѵ�.
	ifstream inputFile(nameFile.data());
	if (!inputFile) {
		throw invalid_argument("Unable to open file");
	}

	// �̸��� �� ���� �ϳ��� �д´�.
	string name;
	while (inputFile >> name) {
		++mNames[name];
	}
}

// �־��� �̸��� ������ �����Ѵ�.
// ���� �־��� �̸��� ���� �Ʊ��� ���� ���Ѵ�.
// �׷��� ���� ��� �̸��� ���� ������ ���鼭 ������ �̸����� ������ ���� �̸��� ������ ��� ����.
// ���������� �� ������ ������ �����Ѵ�.
int NameDB::getNameRank(string_view name) const
{
	int num = getAbsoluteNumber(name);

	// �̸��� ã�Ҵ��� Ȯ���Ѵ�.
	if (num == -1) {
		return -1;
	}

	// �ʿ� �ִ� �̸� �߿��� ������ �̸����� ������ ���� �̸��� ������ ����.
	// �׷� �̸��� ���ٸ� ������ �̸��� 1����. 
	// ������ �̸����� ���� ������ �̸��� ���� ������ ������ �̸��� ������ 1�� �����Ѵ�.
	int rank = 1;
	for (auto& entry : mNames) {
		if (entry.second > num) {
			rank++;
		}
	}

	return rank;
}

// ������ �̸��� ������ �����Ѵ�.
int NameDB::getAbsoluteNumber(string_view name) const
{
	auto res = mNames.find(name.data());
	if (res != end(mNames)) {
		return res->second;
	}

	return -1;
}
