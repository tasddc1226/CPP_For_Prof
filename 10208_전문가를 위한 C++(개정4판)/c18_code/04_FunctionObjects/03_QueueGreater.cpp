#include <queue>
#include <functional>
#include <iostream>
using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<>> myQueue;		// C++14 투명 연산자 펑터를 사용한 예
	//priority_queue<int, vector<int>, greater<int>> myQueue;	// C++14 이전 버전 코드

	myQueue.push(3);
	myQueue.push(4);
	myQueue.push(2);
	myQueue.push(1);

	while (!myQueue.empty()) {
		cout << myQueue.top() <<  " ";
		myQueue.pop();
	}

	return 0;
}
