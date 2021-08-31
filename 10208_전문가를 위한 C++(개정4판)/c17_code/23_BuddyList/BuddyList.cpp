#include "BuddyList.h"

using namespace std;

void BuddyList::addBuddy(const string& name, const string& buddy)
{
	// ���⼭ ������ buddy�� �̹� ��� ���� �ʴ��� Ȯ���Ѵ�.
	if (!isBuddy(name, buddy)) {
		mBuddies.insert({ name, buddy }); // Using initializer_list
	}
}

void BuddyList::removeBuddy(const string& name, const string& buddy)
{
	// 'name' Ű�� ���� ������ ����(���۰� ��)�� ���Ѵ�.
	// ���⼭�� lower_bound()�� upper_bound()�� ����ϴ� ������� �����Ѵ�.
	// ���������� equal_range()�� �����ϴ� ���� �� ȿ�����̴�.
	auto begin = mBuddies.lower_bound(name);  // ������ ����
	auto end = mBuddies.upper_bound(name);    // ������ ��

	// Ű�� 'name'�� ���ҿ� ���� �ݺ��ϸ鼭 ���� 'buddy'�� ���Ҹ� ã�´�.
	// Ű�� 'name'�� ���Ұ� ���ٸ� begin�� end�� �����Ƿ� ������ ������� �ʴ´�.
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->second == buddy) {
			// ��ġ�ϴ� ���Ҹ� ã�Ҵٸ� �ʿ��� �����Ѵ�.
			mBuddies.erase(iter);
			break;
		}
	}
}

bool BuddyList::isBuddy(const string& name, const string& buddy) const
{
	// equal_range()�� 'name' Ű�� ���� ���� ������ ���۰� ���� ���Ѵ�.
	// ���⼭ C++17 ������ ���ε��� ����Ѵ�.
	auto [begin, end] = mBuddies.equal_range(name);
	
	// ���� ����ϴ� �����Ϸ��� C++17 ������ ���ε��� �������� �ʴ´ٸ� ������ ���� �ۼ��Ѵ�.
	//auto range = mBuddies.equal_range(name);
	//auto begin = range.first;  // ������ ����
	//auto end = range.second;   // ������ ��

	// 'name' Ű�� ���� ���ҿ� ���� �ݺ��ϸ鼭 ���� 'buddy'�� ���Ҹ� ã�´�.
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->second == buddy) {
			// ���Ҹ� ã�� ���
			return true;
		}
	}
	// ���Ҹ� ã�� ���� ���
	return false;
}

vector<string> BuddyList::getBuddies(const string& name) const
{
	// equal_range()�� 'name' Ű�� ���� ���� ������ ���۰� ���� ���Ѵ�.
	// ���⼭ C++17 ������ ���ε��� ����Ѵ�.
	auto [begin, end] = mBuddies.equal_range(name);

	// ���� ����ϴ� �����Ϸ��� C++17 ������ ���ε��� �������� �ʴ´ٸ� ������ ���� �ۼ��Ѵ�.
	//auto range = mBuddies.equal_range(name);
	//auto begin = range.first;  // ������ ����
	//auto end = range.second;   // ������ ��

	// �տ��� ���� ������ ���� �̸��� ��� vector�� ��´�.
	vector<string> buddies;
	for (auto iter = begin; iter != end; ++iter) {
		buddies.push_back(iter->second);
	}

	return buddies;
}
