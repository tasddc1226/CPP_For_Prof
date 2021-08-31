#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>

using namespace std;

class Counter
{
public:
	Counter(int id, int numIterations)
		: mId(id), mNumIterations(numIterations)
	{
	}

	void operator()() const
	{
		for (int i = 0; i < mNumIterations; ++i) {
			//unique_lock lock(sTimedMutex, 200ms);  // C++17
			unique_lock<timed_mutex> lock(sTimedMutex, 200ms);
			if (lock) {
				cout << "Counter " << mId << " has value " << i << endl;
			} else {
				// 200ms 이내에 락을 얻지 못한 경우. 출력은 생략
			}
		}
	}

private:
	int mId;
	int mNumIterations;
	static timed_mutex sTimedMutex;
};

timed_mutex Counter::sTimedMutex;

int main()
{
	// 유니폼 초기화 구문
	thread t1{ Counter{ 1, 20 } };

	// 이름 있는 변수 사용
	Counter c(2, 12);
	thread t2(c);

	// 임시 객체 사용
	thread t3(Counter(3, 10));

	// 세 스레드가 마칠 때까지 기다린다.
	t1.join();
	t2.join();
	t3.join();

	return 0;
}
