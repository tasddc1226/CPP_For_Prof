#include <iostream>
#include <thread>
#include <future>

using namespace std;

int CalculateSum(int a, int b)
{
	return a + b;
}

int main()
{
	// packaged_task를 생성해서 CalculateSum을 실행한다.
	packaged_task<int(int, int)> task(CalculateSum);
	// 생성한 packaged_task로부터 CalculateSum의 결과를 담을 future를 받는다.
	auto theFuture = task.get_future();
	// 스레드를 생성한 뒤 앞에서 만든 packaged_task를 이동시키고,
	// 인수를 적절히 전달해서 작업을 수행한다.
	thread theThread{ std::move(task), 39, 3 };
	
	// 필요한 작업을 수행한다.

	// 결과를 가져온다.
	int result = theFuture.get();
	cout << result << endl;

	// 스레드를 조인한다.
	theThread.join();

	return 0;
}
