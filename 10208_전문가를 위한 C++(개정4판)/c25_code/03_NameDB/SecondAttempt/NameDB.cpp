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
		// �־��� �̸��� �����ͺ��̽��� �̹� �ִ��� Ȯ���Ѵ�.
		if (!nameExistsAndIncrement(name)) {
			// �־��� �̸��� �����ͺ��̽��� �̹� �ִٸ� ������ �ϳ� ������Ű�� �� ����� �ǳʶڴ�.
			// �� ��Ͽ� ���Դٸ� �����ͺ��̽��� ���� �̸��̶� ���̹Ƿ�
			// �̸��� �߰��ϰ� ������ �ϳ� ������Ų��.
			addNewName(name);
		}
	}
}

// �����ͺ��̽��� �̸��� �ִٸ� true�� �����ϰ�, �׷��� �ʴٸ� false�� �����Ѵ�.
// �����ͺ��̽����� �̸��� �߰��ߴٸ� ������ �ϳ� ������Ų��.
bool NameDB::nameExistsAndIncrement(string_view name)
{
	// �־��� �̸��� �ʿ��� ã�´�.
	auto res = mNames.find(name.data());
	if (res != end(mNames)) {
		res->second++;
		return true;
	}
	return false;
}

// �����ͺ��̽��� �̸��� ���� �߰��Ѵ�.
void NameDB::addNewName(string_view name)
{
	mNames[name.data()] = 1;
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
