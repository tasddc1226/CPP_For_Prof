#pragma once

#include <string_view>
#include <string>
#include <vector>
#include <utility>

class NameDB
{
public:
	// nameFile에 담긴 이름 목록을 읽어서 데이터베이스에 저장한다.
    // nameFile을 열 수 없거나 읽을 수 없으면 invalid_argument 익셉션을 던진다.
	NameDB(std::string_view nameFile);

	// 이름의 인기순위를 리턴한다(1st, 2nd 등).
    // 주어진 이름이 데이터베이스에 없으면 -1을 리턴한다.
	int getNameRank(std::string_view name) const;

	// 주어진 이름을 가진 아기가 몇 명인지 리턴한다.
    // 입력한 이름을 가진 아기가 없으면 -1을 리턴한다.
	int getAbsoluteNumber(std::string_view name) const;

private:
	std::vector<std::pair<std::string, int>> mNames;

	// 헬퍼 메서드
	bool nameExists(std::string_view name) const;
	void incrementNameCount(std::string_view name);
	void addNewName(std::string_view name);
};
