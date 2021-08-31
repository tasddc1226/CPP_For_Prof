#pragma once

#include <set>
#include <string>
#include <string_view>
#include <vector>
#include <initializer_list>

class AccessList final
{
public:
	// ����Ʈ ������
	AccessList() = default;

	// ������ �ʱ�ȭ�� �����ϴ� ������
	AccessList(std::initializer_list<std::string_view> initlist);

	// ���� ���� ����Ʈ�� ����ڸ� �߰��ϴ� �޼���
	void addUser(std::string_view user);

	// ���� ���� ����Ʈ���� ����ڸ� �����ϴ� �޼���
	void removeUser(std::string_view user);

	// ���� ���� ����Ʈ�� ����ڰ� �ִٸ� true�� �����Ѵ�.
	bool isAllowed(std::string_view user) const;

	// ���� ������ ���� ����ڸ� ��� vector�� ��Ƽ� �����Ѵ�.
	std::vector<std::string> getAllUsers() const;

private:
	std::set<std::string> mAllowed;
};
