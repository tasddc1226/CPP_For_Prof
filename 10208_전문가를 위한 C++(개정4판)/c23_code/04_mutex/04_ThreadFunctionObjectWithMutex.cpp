#include <thread>
#include <iostream>
#include <mutex>

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
			//lock_guard lock(sMutex);  // C++17
			lock_guard<mutex> lock(sMutex);
			cout << "Counter " << mId << " has value " << i << endl;
		}
	}

private:
	int mId;
	int mNumIterations;
	static mutex sMutex;
};

mutex Counter::sMutex;

int main()
{
	// 유니폼 초기화 구문
	thread t1{ Counter{ 1, 20 } };

	// 이름 있는 변수 사용
	Counter c(2, 12);
	thread t2(c);

	// 임시 객체 사용
	thread t3(Counter(3, 10));

	// 세 스레드가 끝날 때까지 기다린다.
	t1.join();
	t2.join();
	t3.join();

	return 0;
}

