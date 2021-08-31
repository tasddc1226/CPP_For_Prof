#include <iostream>
#include <future>

using namespace std;

int calculate()
{
	return 123;
}

int main()
{
	auto myFuture = async(calculate);
	//auto myFuture = async(launch::async, calculate);
	//auto myFuture = async(launch::deferred, calculate);

	// 필요한 작업을 수행한다.

	// 결과를 가져온다.
	int result = myFuture.get();
	cout << result << endl;

	return 0;
}
