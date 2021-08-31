#include <thread>
#include <iostream>

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
			cout << "Counter " << mId << " has value " << i << endl;
		}
	}

private:
	int mId;
	int mNumIterations;
};

int main()
{
	// 유니폼 초기화 구문을 적용한다.
	thread t1{ Counter{ 1, 20 } };

	// 이름 있는 변수를 사용한다.
	Counter c(2, 12);
	thread t2(c);

	// 임시 객체를 사용한다.
	thread t3(Counter(3, 10));

	// 세 스레드가 모두 마칠 때까지 기다린다.
	t1.join();
	t2.join();
	t3.join();

	return 0;
}
