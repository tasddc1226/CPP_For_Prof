#include <vector>
using namespace std;

int main()
{
	vector<int> intVector(10);
	// ���ϴ� �۾��� �����Ѵ�...
	intVector.assign(5, 100);

	intVector.assign({ 1, 2, 3, 4 });

	vector<int> vectorOne(10);
	vector<int> vectorTwo(5, 100);

	vectorOne.swap(vectorTwo);
	// vectorOne�� ���� 100�� ���� �ټ� ���� ����,
	// vectorTwo�� ���� 0�� ���� �� ���� ���� �ȴ�.

	return 0;
}
