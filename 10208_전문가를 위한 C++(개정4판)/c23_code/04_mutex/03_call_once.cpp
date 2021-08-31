#include <thread>
#include <iostream>
#include <mutex>
#include <vector>

using namespace std;

once_flag gOnceFlag;

void initializeSharedResources()
{
	// ... 공유 리소스를 여러 스레드가 사용하도록 초기화한다.

	cout << "Shared resources initialized." << endl;
}

void processingFunction()
{
	// 공유 리소스를 확실히 초기화시킨다.
	call_once(gOnceFlag, initializeSharedResources);

	// ... 필요한 작업을 수행한다. 공유 리소스를 사용하는 코드도 여기에 작성한다.
	cout << "Processing" << endl;
}

int main()
{
	// 스레드 세 개를 구동한다.
	vector<thread> threads(3);
	for (auto& t : threads) {
		t = thread{ processingFunction };
	}

	// 세 스레드가 마칠 때까지 기다린다.
	for (auto& t : threads) {
		t.join();
	}

	return 0;
}
