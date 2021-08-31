#include <thread>
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

void doSomeWork()
{
	for (int i = 0; i < 5; ++i) {
		cout << i << endl;
	}
	cout << "Thread throwing a runtime_error exception..." << endl;
	throw runtime_error("Exception from thread");
}

void threadFunc(exception_ptr& err)
{
	try {
		doSomeWork();
	} catch (...) {
		cout << "Thread caught exception, returning exception..." << endl;
		err = current_exception();
	}
}

void doWorkInThread()
{
	exception_ptr error;
	// ������ ����
	thread t{ threadFunc, ref(error) };
	// �����尡 ������ ������ ��ٸ���.
	t.join();
	// �����忡 �ͼ����� �߻��ߴ��� �˻��Ѵ�.
	if (error) {
		cout << "Main thread received exception, rethrowing it..." << endl;
		rethrow_exception(error);
	} else {
		cout << "Main thread did not receive any exception." << endl;
	}
}

int main()
{
	try {
		doWorkInThread();
	} catch (const exception& e) {
		cout << "Main function caught: '" << e.what() << "'" << endl;
	}
	return 0;
}
