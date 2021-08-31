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
	// ������ �ʱ�ȭ ������ �����Ѵ�.
	thread t1{ Counter{ 1, 20 } };

	// �̸� �ִ� ������ ����Ѵ�.
	Counter c(2, 12);
	thread t2(c);

	// �ӽ� ��ü�� ����Ѵ�.
	thread t3(Counter(3, 10));

	// �� �����尡 ��� ��ĥ ������ ��ٸ���.
	t1.join();
	t2.join();
	t3.join();

	return 0;
}
