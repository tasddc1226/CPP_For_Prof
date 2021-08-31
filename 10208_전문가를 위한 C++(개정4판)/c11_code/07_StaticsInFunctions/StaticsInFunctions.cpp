#include <iostream>

using namespace std;

void performTask()
{
    static bool initialized = false;
    
	if (!initialized) {
		cout << "initializing" << endl;
        // 초기화한다.
        initialized = true;
    }

	// 원하는 작업을 수행한다.
}

int main()
{
	performTask();
	performTask();

	return 0;
}
