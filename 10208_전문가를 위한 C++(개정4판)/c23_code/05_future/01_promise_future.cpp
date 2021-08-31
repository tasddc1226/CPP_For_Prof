#include <iostream>
#include <thread>
#include <future>

using namespace std;

void DoWork(promise<int> thePromise)
{
	// ... �ʿ��� �۾��� �����Ѵ�. ...
	// ���� ����� promise�� �����Ѵ�.
	thePromise.set_value(42);
}

int main()
{
	// �����忡 ������ promise�� �����Ѵ�.
	promise<int> myPromise;
	// �� promise�� ���� future�� �����´�.
	auto theFuture = myPromise.get_future();
	// �����带 �����ϰ� �տ��� ���� promise�� �μ��� �����Ѵ�.
	thread theThread{ DoWork, std::move(myPromise) };

	// �ʿ��� �۾��� �����Ѵ�.

	// ����� �����´�.
	int result = theFuture.get();
	cout << "Result: " << result << endl;

	// �����带 �����Ѵ�.
	theThread.join();

	return 0;
}
