#include "BuddyList.h"
#include <iostream>

using namespace std;

int main()
{
	BuddyList buddies;

	buddies.addBuddy("Harry Potter", "Ron Weasley");
	buddies.addBuddy("Harry Potter", "Hermione Granger");
	buddies.addBuddy("Harry Potter", "Hagrid");
	buddies.addBuddy("Harry Potter", "Draco Malfoy");
	// 실수로 추가한 드라코 말포이를 삭제한다.
	buddies.removeBuddy("Harry Potter", "Draco Malfoy");

	buddies.addBuddy("Hagrid", "Harry Potter");
	buddies.addBuddy("Hagrid", "Ron Weasley");
	buddies.addBuddy("Hagrid", "Hermione Granger");

	auto harrysFriends = buddies.getBuddies("Harry Potter");

	cout << "Harry's friends: " << endl;
	for (const auto& name : harrysFriends) {
		cout << "\t" << name << endl;
	}

	return 0;
}
