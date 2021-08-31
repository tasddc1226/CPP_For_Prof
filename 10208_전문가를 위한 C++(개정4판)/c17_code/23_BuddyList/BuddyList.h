#pragma once

#include <map>
#include <string>
#include <vector>

class BuddyList final
{
public:
	// buddy를 name의 친구로 추가한다.
	void addBuddy(const std::string& name, const std::string& buddy);

	// name의 친구 목록에서 buddy를 제거한다.
	void removeBuddy(const std::string& name, const std::string& buddy);

	// buddy가 name의 친구라면 true를, 그렇지 않으면 false를 리턴한다.
	bool isBuddy(const std::string& name, const std::string& buddy) const;

	// name의 모든 친구가 담긴 목록을 가져온다.
	std::vector<std::string> getBuddies(const std::string& name) const;

private:
	std::multimap<std::string, std::string> mBuddies;
};
