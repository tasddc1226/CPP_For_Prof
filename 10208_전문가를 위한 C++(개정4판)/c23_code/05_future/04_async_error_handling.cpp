#include <iostream>
#include <future>
#include <exception>
#include <stdexcept>

using namespace std;

int calculate()
{
	throw runtime_error("Exception thrown from calculate().");
}

int main()
{
	// 강제로 비동기식으로 실행하도록 launch::async policy를 사용한다.
	auto myFuture = async(launch::async, calculate);

	// 필요한 작업을 수행한다.

	// 결과를 가져온다.
	try {
		int result = myFuture.get();
		cout << result << endl;
	} catch (const exception& ex) {
		cout << "Caught exception: " << ex.what() << endl;
	}

	return 0;
}
