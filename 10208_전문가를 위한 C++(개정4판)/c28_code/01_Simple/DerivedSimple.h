#pragma once

#include "Simple.h"

// Simple Ŭ������ ����ϴ� Ŭ����
class DerivedSimple : public Simple
{
public:
	DerivedSimple();                      // ������

	virtual void publicMethod() override; // �������̵��� �޼���
	virtual void anotherMethod();         // ���� �߰��� �޼���
};
