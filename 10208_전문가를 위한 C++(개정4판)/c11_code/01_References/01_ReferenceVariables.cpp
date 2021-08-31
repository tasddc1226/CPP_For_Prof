#include <string>

std::string getString()
{
	return "Hello world!";
}

int main()
{
	int x = 3, y = 4, z = 5;
	int& xRef = x;
	xRef = 10;
	//  int& emptyRef; // ������ ����!

	//  int& unnamedRef1 = 5;   // ������ ����!
	const int& unnamedRef2 = 5; // ���� ����

	//  std::string& string1 = getString();   // ������ ����!
	const std::string& string2 = getString(); // ���� ����

	xRef = y; // x ���� 4�� �ٲ۴�. xRef�� y�� ����Ű�� ������ �ʴ´�.

	int& zRef = z;
	zRef = xRef; // ���۷����� �ƴ� ���� �����Ѵ�.

	int* intP;
	int*& ptrRef = intP;
	ptrRef = new int;
	*ptrRef = 5;

	int* xPtr = &xRef; // ���۷����� �ּҴ� ���� ���� �����ʹ�.
	*xPtr = 100;

	return 0;
}
