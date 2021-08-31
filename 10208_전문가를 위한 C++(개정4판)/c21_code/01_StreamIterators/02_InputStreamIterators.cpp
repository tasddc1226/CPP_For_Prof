#include <numeric>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
	// 콘솔에서 스트림 끝 문자가 들어올 때까지 입력된 정수의 합을 구한다.
	// 주의e:
	//	윈도우에서 스트림 끝 문자는 Ctrl+Z 입력 후 엔터 키를 쳐야 입력된다.
	//	리눅스에서 스트림 끝 문자는 엔터 키를 쳐서 다음 줄로 넘어간 뒤 Ctrl+D를 눌러야 입력된다.
	cout << "Enter numbers separated by white space." << endl;
	cout << "Press Ctrl+Z followed by Enter to stop." << endl;
	istream_iterator<int> numbersIter(cin);
	istream_iterator<int> endIter;
	int sum = accumulate(numbersIter, endIter, 0);
	cout << "Sum: " << sum << endl;

	return 0;
}
