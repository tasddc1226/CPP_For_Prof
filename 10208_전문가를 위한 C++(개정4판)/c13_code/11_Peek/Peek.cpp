#include <iostream>
#include <string>

using namespace std;

void getReservationData()
{
	string guestName;
	int partySize = 0;
	// 숫자가 나올 때까지 문자를 읽는다.
	char ch;
	cin >> noskipws;
	while (true) {
		// peek()으로 다음 문자를 들여다본다.
		ch = static_cast<char>(cin.peek());
		if (!cin)
			break;
		if (isdigit(ch)) {
			// 다음 문자가 숫자라면 반복문을 종료한다.
			break;
		}
		// 다음 문자가 숫자가 아니라면 계속 읽는다.
		cin >> ch;
		if (!cin)
			break;
		guestName += ch;
	}
	// 스트림에 에러가 발생하지 않았다면 partySize를 읽는다.
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
