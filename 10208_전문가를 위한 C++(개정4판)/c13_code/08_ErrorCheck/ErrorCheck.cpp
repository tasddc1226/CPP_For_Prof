#include <iostream> 
#include <string>

using namespace std;

int main()
{
	cout << "Enter numbers on separate lines to add. "
		<< "Use Control+D to finish (Control+Z in Windows)." << endl;
	int sum = 0;

	if (!cin.good()) {
		cerr << "Standard input is in a bad state!" << endl;
		return 1;
	}

	int number;
	while (!cin.bad()) {
		cin >> number;
		if (cin.good()) {
			sum += number;
		} else if (cin.eof()) {
			break; // 파일 끝에 도달
		} else if (cin.fail()) {
			// 문제 발생!
			cin.clear(); // 에러 상태 제거
			string badToken;
			cin >> badToken; // 잘못된 입력값을 가져온다.
			cerr << "WARNING: Bad input encountered: " << badToken << endl;
		}
	}

	cout << "The sum is " << sum << endl;

	return 0;
}
