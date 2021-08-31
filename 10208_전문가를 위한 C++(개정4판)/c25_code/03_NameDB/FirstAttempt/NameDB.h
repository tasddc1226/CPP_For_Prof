#pragma once

#include <string_view>
#include <string>
#include <vector>
#include <utility>

class NameDB
{
public:
	// nameFile�� ��� �̸� ����� �о �����ͺ��̽��� �����Ѵ�.
    // nameFile�� �� �� ���ų� ���� �� ������ invalid_argument �ͼ����� ������.
	NameDB(std::string_view nameFile);

	// �̸��� �α������ �����Ѵ�(1st, 2nd ��).
    // �־��� �̸��� �����ͺ��̽��� ������ -1�� �����Ѵ�.
	int getNameRank(std::string_view name) const;

	// �־��� �̸��� ���� �ƱⰡ �� ������ �����Ѵ�.
    // �Է��� �̸��� ���� �ƱⰡ ������ -1�� �����Ѵ�.
	int getAbsoluteNumber(std::string_view name) const;

private:
	std::vector<std::pair<std::string, int>> mNames;

	// ���� �޼���
	bool nameExists(std::string_view name) const;
	void incrementNameCount(std::string_view name);
	void addNewName(std::string_view name);
};
