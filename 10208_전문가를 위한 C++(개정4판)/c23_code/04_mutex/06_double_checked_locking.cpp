#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>

using namespace std;

void initializeSharedResources()
{
	// ... 공유 리소스를 여러 스레드가 사용할 수 있도록 초기화한다.

	cout << "Shared resources initialized." << endl;
}

atomic<bool> gInitialized(false);
mutex gMutex;

void processingFunction()
{
	if (!gInitialized) {
		//unique_lock lock(gMutex);  // C++17
		unique_lock<mutex> lock(gMutex);
		if (!gInitialized) {
			initializeSharedResources();
			gInitialized = true;
		}
	}
	cout << "OK" << endl;
}

int main()
{
	vector<thread> threads;

	for (int i = 0; i < 5; ++i) {
		threads.push_back(thread{ processingFunction });
	}

	for (auto& t : threads) {
		t.join();
	}

	return 0;
}
