#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>
#include <exception>

using namespace std;

vector<int> readIntegerFile(string_view fileName)
{
	ifstream inputStream(fileName.data());
	if (inputStream.fail()) {
		// ���� ���� ����: �ͼ����� ������.
		throw invalid_argument("Unable to open the file.");
	}

	// ���Ͽ� ��� �������� �ϳ��� �о ���Ϳ� �߰��Ѵ�.
	vector<int> integers;
	int temp;
	while (inputStream >> temp) {
		integers.push_back(temp);
	}

	if (!inputStream.eof()) {
		// ���� ��(EOF)�� �������� �ʾҴ�.
		// �ٽ� ���� ������ �д� ���߿� ������ �߻��ߴ�.
		// ���� �ͼ����� ������.
		throw runtime_error("Error reading the file.");
	}

	return integers;
}

void myTerminate()
{
	cout << "Uncaught exception!" << endl;
	exit(1);
}

int main()
{
	set_terminate(myTerminate);

	const string fileName = "IntegerFile.txt";
	vector<int> myInts = readIntegerFile(fileName);

	for (const auto& element : myInts) {
		cout << element << " ";
	}
	cout << endl;

	return 0;
}
