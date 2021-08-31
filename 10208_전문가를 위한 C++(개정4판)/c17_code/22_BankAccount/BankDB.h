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
	// 은행 데이터베이스에 계좌를 추가한다. 같은 계좌가 이미 있다면 추가하지 않는다.
	// 계좌를 추가했다면 true를 리턴하고, 그렇지 않으면 false를 리턴한다.
	bool addAccount(const BankAccount& account);

	// acctNum으로 지정한 계좌를 데이터베이스에서 삭제한다.
	void deleteAccount(int acctNum);

	// 번호나 클라이언트 이름으로 지정한 계좌에 대한 레퍼런스를 리턴한다.
	// 지정한 계좌가 없다면 out_of_range 익셉션을 던진다.
	BankAccount& findAccount(int acctNum);
	BankAccount& findAccount(std::string_view name);

	// db에 있는 계좌를 모두 이 데이터베이스에 추가한다.
	// 그런 다음 db에 있는 계좌를 모두 삭제한다.
	void mergeDatabase(BankDB& db);

private:
	std::map<int, BankAccount> mAccounts;
};

