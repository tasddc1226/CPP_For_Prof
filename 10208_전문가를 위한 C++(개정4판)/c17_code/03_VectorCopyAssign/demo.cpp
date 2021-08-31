#include <vector>
using namespace std;

int main()
{
	vector<int> intVector(10);
	// 원하는 작업을 수행한다...
	intVector.assign(5, 100);

	intVector.assign({ 1, 2, 3, 4 });

	vector<int> vectorOne(10);
	vector<int> vectorTwo(5, 100);

	vectorOne.swap(vectorTwo);
	// vectorOne은 값이 100인 원소 다섯 개를 갖고,
	// vectorTwo는 값이 0인 원소 열 개를 갖게 된다.

	return 0;
}
