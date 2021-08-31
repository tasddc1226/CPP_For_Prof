#include <utility>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	// 인수가 두 개인 생성자와 디폴트 생성자
	pair<string, int> myPair("hello", 5);
	pair<string, int> myOtherPair;

	// first와 second에 직접 대입할 수 있다.
	myOtherPair.first = "hello";
	myOtherPair.second = 6;

	// 복제 생성자
	pair<string, int> myThirdPair(myOtherPair);

	// operator<
	if (myPair < myOtherPair) {
		cout << "myPair is less than myOtherPair" << endl;
	} else {
		cout << "myPair is greater than or equal to myOtherPair" << endl;
	}

	// operator==
	if (myOtherPair == myThirdPair) {
		cout << "myOtherPair is equal to myThirdPair" << endl;
	} else {
		cout << "myOtherPair is not equal to myThirdPair" << endl;
	}

	pair<int, double> aPair = make_pair(5, 10.10);
	auto aSecondPair = make_pair(5, 10.10);
	auto aThirdPair = pair(5, 10.10);
	
	// C++17부터 추가된 구조적 바인딩을 이용하면
	// pair에 속한 원소를 각자 다른 변수로 분리할 수 있다.
	auto[theString, theInt] = myPair;
	cout << "theString: " << theString << endl;
	cout << "theInt: " << theInt << endl;

	return 0;
}
