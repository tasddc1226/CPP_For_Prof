#include <iostream>
#include <string>

using namespace std;

void getReservationData()
{
	string guestName;
	int partySize = 0;
	// ���ڰ� ���� ������ ���ڸ� �д´�.
	char ch;
	cin >> noskipws;
	while (true) {
		// peek()���� ���� ���ڸ� �鿩�ٺ���.
		ch = static_cast<char>(cin.peek());
		if (!cin)
			break;
		if (isdigit(ch)) {
			// ���� ���ڰ� ���ڶ�� �ݺ����� �����Ѵ�.
			break;
		}
		// ���� ���ڰ� ���ڰ� �ƴ϶�� ��� �д´�.
		cin >> ch;
		if (!cin)
			break;
		guestName += ch;
	}
	// ��Ʈ���� ������ �߻����� �ʾҴٸ� partySize�� �д´�.
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
