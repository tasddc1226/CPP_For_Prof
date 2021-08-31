#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void getReservationData()
{
	string guestName;
	int partySize = 0;
	// ���ڰ� ���� ������ ���ڸ� �д´�.
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
	// ��Ʈ���� ���� ���°� �ƴϸ� partySize ���� �д´�.
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
