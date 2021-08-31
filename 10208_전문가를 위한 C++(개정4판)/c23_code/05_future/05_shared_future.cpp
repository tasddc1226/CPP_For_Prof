#include <future>

using namespace std;

int main()
{
	promise<void> thread1Started, thread2Started;

	promise<int> signalPromise;
	auto signalFuture = signalPromise.get_future().share();
	//shared_future<int> signalFuture(signalPromise.get_future());

	auto function1 = [&thread1Started, signalFuture] {
		thread1Started.set_value();
		// �Ű������� ������ ������ ��ٸ���.
		int parameter = signalFuture.get();
		// ...
	};

	auto function2 = [&thread2Started, signalFuture] {
		thread2Started.set_value();
		// �Ű������� ������ ������ ��ٸ���.
		int parameter = signalFuture.get();
		// ...
	};

	// �� ���� ǥ������ �񵿱������ �����Ѵ�.
	// �̶� �ݵ�� async()�� ������ future�� ĸó�Ѵ�.
	auto result1 = async(launch::async, function1);
	auto result2 = async(launch::async, function2);

	// �� �����尡 ������ ������ ��ٸ���.
	thread1Started.get_future().wait();
	thread2Started.get_future().wait();

	// ���� �� ������� �Ű������� ��ٸ���.
	// �Ű������� �����ؼ� �� ������ ��� �����.
	signalPromise.set_value(42);
}