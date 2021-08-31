#include <thread>
#include <iostream>
#include <mutex>
#include <vector>

using namespace std;

once_flag gOnceFlag;

void initializeSharedResources()
{
	// ... ���� ���ҽ��� ���� �����尡 ����ϵ��� �ʱ�ȭ�Ѵ�.

	cout << "Shared resources initialized." << endl;
}

void processingFunction()
{
	// ���� ���ҽ��� Ȯ���� �ʱ�ȭ��Ų��.
	call_once(gOnceFlag, initializeSharedResources);

	// ... �ʿ��� �۾��� �����Ѵ�. ���� ���ҽ��� ����ϴ� �ڵ嵵 ���⿡ �ۼ��Ѵ�.
	cout << "Processing" << endl;
}

int main()
{
	// ������ �� ���� �����Ѵ�.
	vector<thread> threads(3);
	for (auto& t : threads) {
		t = thread{ processingFunction };
	}

	// �� �����尡 ��ĥ ������ ��ٸ���.
	for (auto& t : threads) {
		t.join();
	}

	return 0;
}
