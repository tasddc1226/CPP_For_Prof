#include <vector>
#include <string>
#include <functional>
#include <iostream>

using namespace std;

int main()
{
	string str1 = "Hello";
	string str2 = "World";

	// string�� ���� ���۷����� ���� vector�� �����Ѵ�.
	vector<reference_wrapper<string>> vec{ ref(str1) };
	vec.push_back(ref(str2));  // push_back()���� ������ �� �ִ�.

	// �տ��� ���� vector�� �� ��° ����(���۷���)�� �����ϴ� string ���� �����Ѵ�.
	vec[1].get() += "!";

	// ���� ���(����� str2 ��)�� ����Ѵ�.
	cout << str1 << " " << str2 << endl;
}