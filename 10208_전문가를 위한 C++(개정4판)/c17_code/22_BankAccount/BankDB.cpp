#include "BankDB.h"
#include <utility>
#include <stdexcept>

using namespace std;

bool BankDB::addAccount(const BankAccount& acct)
{
	// ������ ���� ��ȣ�� Ű�� ����ؼ� ������ �߰��ϴ� ������ �����Ѵ�.
	auto res = mAccounts.emplace(acct.getAcctNum(), acct);
	// �Ǵ� ������ ���� �ۼ��ص� �ȴ�.
	// auto res = mAccounts.insert(make_pair(acct.getAcctNum(), acct));

	// ���� ����ϴ� �����Ϸ��� C++11 'auto'�� �������� �ʴ´ٸ� ������ ���� �ۼ��Ѵ�.
	// insert()���� �����ϴ� pair�� ������ ������ �����Ѵ�.
	//pair<map<int, BankAccount>::iterator, bool> res;
	// ���¹�ȣ�� Ű�� �����ؼ� ���� insert ������ �����Ѵ�.
	//res = mAccounts.insert(make_pair(acct.getAcctNum(), acct));

	// ������ ������ ���� ���θ� ǥ���ϴ� pair�� bool �ʵ带 �����Ѵ�.
	return res.second;
}

void BankDB::deleteAccount(int acctNum)
{
	mAccounts.erase(acctNum);
}

BankAccount& BankDB::findAccount(int acctNum)
{
	// find()�� ������ Ű�� ���Ҹ� ã�´�.
	auto it = mAccounts.find(acctNum);
	// ���� ����ϴ� �����Ϸ��� C++11 'auto'�� �������� �ʴ´ٸ� ������ ���� �ۼ��Ѵ�.
	//map<int, BankAccount>::iterator it = mAccounts.find(acctNum);

	if (it == end(mAccounts)) {
		throw out_of_range("No account with that number.");
	}

	// map�� ���� �ݺ��ڴ� Ű/�� pair�� ����Ų�ٴ� ���� ����Ѵ�.
	return it->second;
}

BankAccount& BankDB::findAccount(string_view name)
{
	// Ű ���� ���Ҹ� ã������ ���Ҹ� ���������� Ž���ؾ� �Ѵ�.
	// C++17���� �߰��� ������ ���ε��� Ȱ���Ѵ�.
	for (auto& [acctNum, account] : mAccounts) {
		if (account.getClientName() == name) {
			return account;  // ���Ҹ� ã�� ���
		}
	}

	// ���� ����ϴ� �����Ϸ��� C++17 ������ ���ε��� �������� �ʴ´ٸ� ������ ���� �ۼ��Ѵ�.
	//for (auto& p : mAccounts) {
	//	if (p.second.getClientName() == name) {
	//		return p.second;  // found it!
	//	}
	//}

	// ���� ����ϴ� �����Ϸ��� C++11 ���� ��� for�� �������� �ʴ´ٸ� ������ ���� �ۼ��Ѵ�.
	//for (map<int, BankAccount>::iterator it = mAccounts.begin();
	//     it != mAccounts.end(); ++it) {
	//  if (it->second.getClientName() == name) {
	//    return it->second;  // found it!
	//  }
	//}
	throw out_of_range("No account with that name.");
}

void BankDB::mergeDatabase(BankDB& db)
{
	// C++17 merge()�� ����Ѵ�.
	mAccounts.merge(db.mAccounts);
	// �Ǵ� ������ ���� �ۼ��Ѵ�.
    // Or: mAccounts.insert(begin(db.mAccounts), end(db.mAccounts));

	// ���� ���� �����ͺ��̽��� �����Ѵ�.
	db.mAccounts.clear();
}
