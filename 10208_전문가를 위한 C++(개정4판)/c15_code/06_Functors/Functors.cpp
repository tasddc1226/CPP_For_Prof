#include <string>

using namespace std;

class FunctionObject
{
public:
	int operator() (int param);	// �Լ� ȣ�� ������
	void operator() (string_view /*str*/) {}
	int doSquare(int param);		// �Ϲ� �޼���
};

// �����ε��� �Լ� ȣ�� �������� ���� �ڵ�
int FunctionObject::operator() (int param)
{
	return doSquare(param);
}

// �Ϲ� �޼����� ���� �ڵ�
int FunctionObject::doSquare(int param)
{
	return param * param;
}

int main()
{
	int x = 3, xSquared, xSquaredAgain;
	FunctionObject square;

	xSquared = square(x);				// �Լ� ȣ�� �����ڸ� ȣ���Ѵ�.
	xSquaredAgain = square.doSquare(x);	// �Ϲ� �޼��带 ȣ���Ѵ�.

	return 0;
}

