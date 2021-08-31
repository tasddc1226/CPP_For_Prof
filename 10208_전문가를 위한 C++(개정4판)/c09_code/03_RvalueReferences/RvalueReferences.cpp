#include <iostream>
#include <string>

using namespace std;

void helper(std::string&& message)
{
}

// ������ ���۷��� �Ű�����
void handleMessage(std::string& message)
{
	cout << "handleMessage with lvalue reference: " << message << endl;
}

// ������ ���۷��� �Ű�����
void handleMessage(std::string&& message)
{
	cout << "handleMessage with rvalue reference: " << message << endl;
	helper(std::move(message));
}

int main()
{
	std::string a = "Hello ";
	std::string b = "World";

	// �̸� �ִ� ������ ó���Ѵ�.
	handleMessage(a);             // handleMessage(string& value)�� ȣ���Ѵ�.

	// ǥ������ ó���Ѵ�.
	handleMessage(a + b);         // handleMessage(string&& value)�� ȣ���Ѵ�.

	// ���ͷ��� ó���Ѵ�.
	handleMessage("Hello World"); // handleMessage(string&& value)�� ȣ���Ѵ�.

	// �̸� �ִ� ������ ó���ϰ� ������ ���۷��� �޼��带 ����ϵ��� �����Ѵ�.
	handleMessage(std::move(b));  // handleMessage(string&& value)�� ȣ���Ѵ�.

	return 0;
}
