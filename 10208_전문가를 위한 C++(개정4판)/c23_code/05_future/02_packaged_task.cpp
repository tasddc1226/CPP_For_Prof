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
	// packaged_task�� �����ؼ� CalculateSum�� �����Ѵ�.
	packaged_task<int(int, int)> task(CalculateSum);
	// ������ packaged_task�κ��� CalculateSum�� ����� ���� future�� �޴´�.
	auto theFuture = task.get_future();
	// �����带 ������ �� �տ��� ���� packaged_task�� �̵���Ű��,
	// �μ��� ������ �����ؼ� �۾��� �����Ѵ�.
	thread theThread{ std::move(task), 39, 3 };
	
	// �ʿ��� �۾��� �����Ѵ�.

	// ����� �����´�.
	int result = theFuture.get();
	cout << result << endl;

	// �����带 �����Ѵ�.
	theThread.join();

	return 0;
}
