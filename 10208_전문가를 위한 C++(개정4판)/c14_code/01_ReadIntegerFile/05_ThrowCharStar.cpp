#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <exception>

using namespace std;

vector<int> readIntegerFile(string_view fileName)
{
	ifstream inputStream(fileName.data());
	if (inputStream.fail()) {
		// ���� ���� ����: �ͼ����� ������.
		throw "Unable to open file";
	}

	// ���Ͽ� ��� �������� �ϳ��� �о ���Ϳ� �߰��Ѵ�.
	vector<int> integers;
	int temp;
	while (inputStream >> temp) {
		integers.push_back(temp);
	}
	return integers;
}

int main()
{
	const string fileName = "IntegerFile.txt";
	vector<int> myInts;

	try {
		myInts = readIntegerFile(fileName);
	} catch (const char* e) {
		cerr << e << endl;
		return 1;
	}

	for (const auto& element : myInts) {
		cout << element << " ";
	}
	cout << endl;

	return 0;
}
