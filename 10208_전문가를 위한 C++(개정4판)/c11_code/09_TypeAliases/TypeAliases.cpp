#include <vector>
#include <string>

//void processVector(const std::vector<std::string>& vec)
//{
//    // 본문 생략
//}

using StringVector = std::vector<std::string>;

void processVector(const StringVector& vec)
{
	// 본문 생략
}

int main()
{
	//std::vector<std::string> myVector;
	StringVector myVector;
	processVector(myVector);
	// 나머지 부분...
	return 0;
}
