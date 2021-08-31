#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void getReservationData()
{
	string guestName;
	int partySize = 0;
	// 숫자가 나올 때까지 문자를 읽는다.
	char ch;
	cin >> noskipws;
	while (cin >> ch) {
		if (isdigit(ch)) {
			cin.unget();
			if (cin.fail())
				cout << "unget() failed" << endl;
			break;
		}
		guestName += ch;
	}
	// 스트림이 에러 상태가 아니면 partySize 값을 읽는다.
	if (cin)
		cin >> partySize;
	if (!cin) {
		cerr << "Error getting party size." << endl;
		return;
	}

	cout << "Thank you '" << guestName
		<< "', party of " << partySize << endl;
	if (partySize > 10) {
		cout << "An extra gratuity will apply." << endl;
	}
}

int main()
{
	getReservationData();

	return 0;
}
