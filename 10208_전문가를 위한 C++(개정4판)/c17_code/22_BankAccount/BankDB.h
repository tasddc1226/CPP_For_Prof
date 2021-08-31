#pragma once

#include <map>
#include <string>
#include <string_view>

class BankAccount final
{
public:
	BankAccount(int acctNum, std::string_view name) : mAcctNum(acctNum), mClientName(name) {}

	void setAcctNum(int acctNum) { mAcctNum = acctNum; }
	int getAcctNum() const { return mAcctNum; }

	void setClientName(std::string_view name) { mClientName = name; }
	std::string_view getClientName() const { return mClientName; }

private:
	int mAcctNum;
	std::string mClientName;
};

class BankDB final
{
public:
	// ���� �����ͺ��̽��� ���¸� �߰��Ѵ�. ���� ���°� �̹� �ִٸ� �߰����� �ʴ´�.
	// ���¸� �߰��ߴٸ� true�� �����ϰ�, �׷��� ������ false�� �����Ѵ�.
	bool addAccount(const BankAccount& account);

	// acctNum���� ������ ���¸� �����ͺ��̽����� �����Ѵ�.
	void deleteAccount(int acctNum);

	// ��ȣ�� Ŭ���̾�Ʈ �̸����� ������ ���¿� ���� ���۷����� �����Ѵ�.
	// ������ ���°� ���ٸ� out_of_range �ͼ����� ������.
	BankAccount& findAccount(int acctNum);
	BankAccount& findAccount(std::string_view name);

	// db�� �ִ� ���¸� ��� �� �����ͺ��̽��� �߰��Ѵ�.
	// �׷� ���� db�� �ִ� ���¸� ��� �����Ѵ�.
	void mergeDatabase(BankDB& db);

private:
	std::map<int, BankAccount> mAccounts;
};

