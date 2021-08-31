#include <iostream>
#include <string>
#include <string_view>

using namespace std;

void handleValue(int value)
{
	cout << "Integer: " << value << endl;
}
void handleValue(double value)
{
	cout << "Double: " << value << endl;
}
void handleValue(string_view value)
{
	cout << "String: " << value << endl;
}



// �� ���� ����� �̿��ϴ� ù ��° ����
void processValues()	// ���̽� ���̽�
{
	// ���̽� ���̽��� ���ؼ� Ư���� �� ���� ����.
}

template<typename T1, typename... Tn>
void processValues(T1 arg1, Tn... args)
{
	handleValue(arg1);
	processValues(args...);
}



// ������ ���۷��� ���� ����� �̿��ϴ� �� ��° ����
void processValuesRValueRefs()	// ���̽� ���̽�
{
	// ���̽� ���̽��� ���� Ư���� �� ���� ����.
}

template<typename T1, typename... Tn>
void processValuesRValueRefs(T1&& arg1, Tn&&... args)
{
	handleValue(std::forward<T1>(arg1));
	processValuesRValueRefs(std::forward<Tn>(args)...);
}



int main()
{
	processValues(1, 2, 3.56, "test", 1.1f);
	cout << endl;
	processValuesRValueRefs(1, 2, 3.56, "test", 1.1f);

	return 0;
}
