#include <vector>
#include <iostream>

using namespace std;

int main()
{
    // ������ ���� ���͸� �����Ѵ�.
    vector<int> myVector = { 11, 22 };

	// push_back()���� ���Ϳ� ������ �� �� �߰��Ѵ�.
    myVector.push_back(33);
    myVector.push_back(44);

	// ���ҿ� �����Ѵ�.
	cout << "1st element: " << myVector[0] << endl;
    
	return 0;
}
