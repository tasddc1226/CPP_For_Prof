#include "BuddyList.h"

using namespace std;

void BuddyList::addBuddy(const string& name, const string& buddy)
{
	// 여기서 지정한 buddy가 이미 들어 있지 않는지 확인한다.
	if (!isBuddy(name, buddy)) {
		mBuddies.insert({ name, buddy }); // Using initializer_list
	}
}

void BuddyList::removeBuddy(const string& name, const string& buddy)
{
	// 'name' 키로 구한 원소의 범위(시작과 끝)을 구한다.
	// 여기서는 lower_bound()와 upper_bound()를 사용하는 방식으로 구현한다.
	// 실전에서는 equal_range()로 구현하는 것이 더 효율적이다.
	auto begin = mBuddies.lower_bound(name);  // 범위의 시작
	auto end = mBuddies.upper_bound(name);    // 범위의 끝

	// 키가 'name'인 원소에 대해 반복하면서 값이 'buddy'인 원소를 찾는다.
	// 키가 'name'인 원소가 없다면 begin과 end가 같으므로 루프가 실행되지 않는다.
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->second == buddy) {
			// 일치하는 원소를 찾았다면 맵에서 제거한다.
			mBuddies.erase(iter);
			break;
		}
	}
}

bool BuddyList::isBuddy(const string& name, const string& buddy) const
{
	// equal_range()로 'name' 키에 대한 원소 범위의 시작과 끝을 구한다.
	// 여기서 C++17 구조적 바인딩을 사용한다.
	auto [begin, end] = mBuddies.equal_range(name);
	
	// 현재 사용하는 컴파일러가 C++17 구조적 바인딩을 지원하지 않는다면 다음과 같이 작성한다.
	//auto range = mBuddies.equal_range(name);
	//auto begin = range.first;  // 범위의 시작
	//auto end = range.second;   // 범위의 끝

	// 'name' 키에 대한 원소에 대해 반복하면서 값이 'buddy'인 원소를 찾는다.
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->second == buddy) {
			// 원소를 찾은 경우
			return true;
		}
	}
	// 원소를 찾지 못한 경우
	return false;
}

vector<string> BuddyList::getBuddies(const string& name) const
{
	// equal_range()로 'name' 키에 대한 원소 범위의 시작과 끝을 구한다.
	// 여기서 C++17 구조적 바인딩을 사용한다.
	auto [begin, end] = mBuddies.equal_range(name);

	// 현재 사용하는 컴파일러가 C++17 구조적 바인딩을 지원하지 않는다면 다음과 같이 작성한다.
	//auto range = mBuddies.equal_range(name);
	//auto begin = range.first;  // 범위의 시작
	//auto end = range.second;   // 범위의 끝

	// 앞에서 구한 범위에 속한 이름을 모두 vector에 담는다.
	vector<string> buddies;
	for (auto iter = begin; iter != end; ++iter) {
		buddies.push_back(iter->second);
	}

	return buddies;
}
