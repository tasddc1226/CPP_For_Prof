#include "DerivedSimple.h"

DerivedSimple::DerivedSimple() : Simple() 
{
	// ������ ���� �ڵ�
}

void DerivedSimple::publicMethod()
{
	// �������̵��� �޼����� ���� �ڵ�
	Simple::publicMethod(); // ���̽� Ŭ������ ������ �� �ִ�.
}

void DerivedSimple::anotherMethod()
{
	// ���� �߰��� �޼����� ���� �ڵ�
}
