#include "NameDB.h"
#include <stdexcept>
#include <fstream>

using namespace std;

// ���Ͽ��� ���� �̸��� �����ͺ��̽��� �����Ѵ�.
// �����ͺ��̽��� �̸�/�� ���� ��� vector�� �����Ѵ�.
// �� �׸񸶴� �̸��� �� �̸��� ���� �����Ϳ� ���� Ƚ���� ��� �ִ�.
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
		// �־��� �̸��� �����ͺ��̽��� �̹� �ִ��� Ȯ���Ѵ�.
		if (nameExists(name)) {
			// �־��� �̸��� �����ͺ��̽��� �ִٸ� Ƚ���� �����Ѵ�.
			incrementNameCount(name);
		} else {
			// �����ͺ��̽��� �̸��� ���ٸ� ���� �߰��ϰ� Ƚ���� 1�� �����Ѵ�.
			addNewName(name);
		}
	}
}

// �����ͺ��̽��� �̸��� �ִٸ� true�� �����ϰ�, �׷��� �ʴٸ� false�� �����Ѵ�.
bool NameDB::nameExists(string_view name) const
{
	// �̸��� ���� ���Ϳ� ���� ������ ���鼭 �־��� �̸��� �˻��Ѵ�.
	for (auto& entry : mNames) {
		if (entry.first == name) {
			return true;
		}
	}
	return false;
}

// ���� ����(Precondition): �̸��� ���� ���Ϳ� �־��� �̸��� �����ؾ� �Ѵ�.
// ���� ����(Postcondition): �� �̸��� ���� Ƚ���� �ϳ� ������Ų��.
void NameDB::incrementNameCount(string_view name)
{
	for (auto& entry : mNames) {
		if (entry.first == name) {
			entry.second++;
			return;
		}
	}
}

// �����ͺ��̽��� �� �̸��� �߰��Ѵ�.
void NameDB::addNewName(string_view name)
{
	mNames.push_back(make_pair(name.data(), 1));
}

// �̸��� ������ �����Ѵ�.
// ���� �־��� �̸��� ���� �Ż��� ���� ��ȸ�Ѵ�.
// �׷��� ���� ��� �̸��� ���� �ݺ����� ���鼭
// �־��� �̸����� ������ ���� �̸��� ���� ���� ������ �����Ѵ�.
int NameDB::getNameRank(string_view name) const
{
	// getAbsoluteNumber() �޼���� ó���Ѵ�.
	int num = getAbsoluteNumber(name);

	// �̸��� ã�Ҵ��� Ȯ���Ѵ�.
	if (num == -1) {
		return -1;
	}

	// �־��� �̸����� ���� ���� �̸��� ���Ϳ��� ��� ã�´�.
	// �־��� �̸����� ������ ���� �̸��� ���ٸ� �� �̸��� 1���� �����.
	// �־��� �̸����� �󵵰� ���� �̸��� ������ 1�� �����Ѵ�.
	int rank = 1;
	for (auto& entry : mNames) {
		if (entry.second > num) {
			rank++;
		}
	}

	return rank;
}

// �־��� �̸��� ���� �����Ѵ�.
int NameDB::getAbsoluteNumber(string_view name) const
{
	for (auto& entry : mNames) {
		if (entry.first == name) {
			return entry.second;
		}
	}
	return -1;
}
