#pragma once

#include <set>
#include <string>
#include <string_view>
#include <vector>
#include <initializer_list>

class AccessList final
{
public:
	// 디폴트 생성자
	AccessList() = default;

	// 유니폼 초기화를 지원하는 생성자
	AccessList(std::initializer_list<std::string_view> initlist);

	// 접근 권한 리스트에 사용자를 추가하는 메서드
	void addUser(std::string_view user);

	// 접근 권한 리스트에서 사용자를 삭제하는 메서드
	void removeUser(std::string_view user);

	// 접근 권한 리스트에 사용자가 있다면 true를 리턴한다.
	bool isAllowed(std::string_view user) const;

	// 접근 권한을 가진 사용자를 모두 vector에 담아서 리턴한다.
	std::vector<std::string> getAllUsers() const;

private:
	std::set<std::string> mAllowed;
};
