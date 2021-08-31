#include <map>
#include <iostream>

using namespace std;

class Data final
{
public:
	explicit Data(int value = 0) : mValue(value) { }
	int getValue() const { return mValue; }
	void setValue(int value) { mValue = value; }

private:
	int mValue;
};

int main()
{
	map<int, Data> dataMap;
	dataMap[1] = Data(4);
	dataMap[1] = Data(6);

	auto it = dataMap.find(1);
	// 현재 사용하는 컴파일러가 C++11 auto 키워드를 지원하지 않을 경우
	//map<int, Data>::iterator it = dataMap.find(1);
	if (it != end(dataMap)) {
		it->second.setValue(100);
	}

	return 0;
}
