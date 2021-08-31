#include <vector>
#include <iostream>

using namespace std;

int main()
{
    // 정수에 대한 벡터를 생성한다.
    vector<int> myVector = { 11, 22 };

	// push_back()으로 벡터에 정수를 좀 더 추가한다.
    myVector.push_back(33);
    myVector.push_back(44);

	// 원소에 접근한다.
	cout << "1st element: " << myVector[0] << endl;
    
	return 0;
}
