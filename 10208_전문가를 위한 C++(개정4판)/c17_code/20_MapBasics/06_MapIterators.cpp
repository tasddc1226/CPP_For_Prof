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
	dataMap[1] = Data(6); // 키가 1인 원소의 값을 바꾼다.

	// C++11 auto 키워드
	for (auto iter = cbegin(dataMap); iter != cend(dataMap); ++iter) {
		cout << iter->second.getValue() << endl;
	}

	// C++11 범위 기반 for문
	for (const auto& p : dataMap) {
		cout << p.second.getValue() << endl;
	}

	// 범위 기반 for문과 C++17 구조적 바인딩
	for (const auto& [key, data] : dataMap) {
		cout << data.getValue() << endl;
	}

	// 현재 사용하는 컴파일러에서 앞에 나온 C++11 기능을 지원하지 않는 경우
	for (map<int, Data>::const_iterator iter = dataMap.begin();
		iter != dataMap.end(); ++iter) {
		cout << iter->second.getValue() << endl;
	}

	return 0;
}
