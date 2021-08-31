#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream fout("test.out");
	if (!fout) {
		cerr << "Error opening test.out for writing" << endl;
		return 1;
	}

	// 1. "12345"�� ��Ʈ���� ����Ѵ�.
	fout << "12345";

	// 2. ���� ��ġ�� 5���� Ȯ���Ѵ�.
	streampos curPos = fout.tellp();
	if (5 == curPos) {
		cout << "Test passed: Currently at position 5" << endl;
	} else {
		cout << "Test failed: Not at position 5" << endl;
	}

	// 3. ��Ʈ���� ���� ��ġ�� 2�� �ű��.
	fout.seekp(2, ios_base::beg);

	// 4. ��ġ 2�� 0�� ���� ��Ʈ���� �ݴ´�.
	fout << 0;
	fout.close();

	// 5. test.out�� ���� �Է� ��Ʈ���� ����.
	ifstream fin("test.out");
	if (!fin) {
		cerr << "Error opening test.out for reading" << endl;
		return 1;
	}

	// 6. ù ��° ��ū�� ���� Ÿ���� ������ �д´�.
	int testVal;
	fin >> testVal;
	if (!fin) {
		cerr << "Error reading from file" << endl;
		return 1;
	}

	// 7. ���� ���� 12045���� Ȯ���Ѵ�.
	const int expected = 12045;
	if (testVal == expected) {
		cout << "Test passed: Value is " << expected << endl;
	} else {
		cout << "Test failed: Value is not " << expected
			<< " (it was " << testVal << ")" << endl;
	}

	return 0;
}
