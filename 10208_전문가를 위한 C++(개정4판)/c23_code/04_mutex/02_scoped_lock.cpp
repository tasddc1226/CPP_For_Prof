#include <mutex>

using namespace std;

mutex mut1;
mutex mut2;

void process()
{
	//scoped_lock locks(mut1, mut2);
	scoped_lock<mutex, mutex> locks(mut1, mut2);

	// 락을 얻은 경우
} // 블록을 벗어나면 락이 자동으로 해제된다.

int main()
{
	process();
	
	return 0;
}
