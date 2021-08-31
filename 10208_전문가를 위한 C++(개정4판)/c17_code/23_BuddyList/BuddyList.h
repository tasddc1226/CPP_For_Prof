#pragma once

#include <map>
#include <string>
#include <vector>

class BuddyList final
{
public:
	// buddy�� name�� ģ���� �߰��Ѵ�.
	void addBuddy(const std::string& name, const std::string& buddy);

	// name�� ģ�� ��Ͽ��� buddy�� �����Ѵ�.
	void removeBuddy(const std::string& name, const std::string& buddy);

	// buddy�� name�� ģ����� true��, �׷��� ������ false�� �����Ѵ�.
	bool isBuddy(const std::string& name, const std::string& buddy) const;

	// name�� ��� ģ���� ��� ����� �����´�.
	std::vector<std::string> getBuddies(const std::string& name) const;

private:
	std::multimap<std::string, std::string> mBuddies;
};
