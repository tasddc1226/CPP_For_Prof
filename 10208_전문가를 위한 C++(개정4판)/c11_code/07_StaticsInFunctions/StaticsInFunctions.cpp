#include <iostream>

using namespace std;

void performTask()
{
    static bool initialized = false;
    
	if (!initialized) {
		cout << "initializing" << endl;
        // �ʱ�ȭ�Ѵ�.
        initialized = true;
    }

	// ���ϴ� �۾��� �����Ѵ�.
}

int main()
{
	performTask();
	performTask();

	return 0;
}
