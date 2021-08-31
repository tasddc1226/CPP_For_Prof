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
	dataMap[1] = Data(6); // Ű�� 1�� ������ ���� �ٲ۴�.

	// C++11 auto Ű����
	for (auto iter = cbegin(dataMap); iter != cend(dataMap); ++iter) {
		cout << iter->second.getValue() << endl;
	}

	// C++11 ���� ��� for��
	for (const auto& p : dataMap) {
		cout << p.second.getValue() << endl;
	}

	// ���� ��� for���� C++17 ������ ���ε�
	for (const auto& [key, data] : dataMap) {
		cout << data.getValue() << endl;
	}

	// ���� ����ϴ� �����Ϸ����� �տ� ���� C++11 ����� �������� �ʴ� ���
	for (map<int, Data>::const_iterator iter = dataMap.begin();
		iter != dataMap.end(); ++iter) {
		cout << iter->second.getValue() << endl;
	}

	return 0;
}
