#include <mutex>

using namespace std;

mutex mut1;
mutex mut2;

void process()
{
	//unique_lock lock1(mut1, defer_lock);  // C++17
	//unique_lock lock2(mut2, defer_lock);  // C++17
	unique_lock<mutex> lock1(mut1, defer_lock);
	unique_lock<mutex> lock2(mut2, defer_lock);
	lock(lock1, lock2);
	// 락을 얻은 경우
} // 블록을 벗어나면 락이 자동으로 해제된다.

int main()
{
	process();
	
	return 0;
}
