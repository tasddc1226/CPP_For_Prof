#include "Simple.h"

int Simple::sStaticInt = 0;   // static ������ ��� �ʱ�ȭ

Simple::Simple() : mPublicInteger(40)
{
	// ������ ���� �ڵ�
}

void Simple::publicMethod() { /* public �޼��� ���� �ڵ� */ }

void Simple::protectedMethod() { /* protected �޼��� ���� �ڵ� */ }

void Simple::privateMethod() { /* private �޼��� ���� �ڵ� */ }

int main()
{
	Simple mySimple;
	return 0;
}
