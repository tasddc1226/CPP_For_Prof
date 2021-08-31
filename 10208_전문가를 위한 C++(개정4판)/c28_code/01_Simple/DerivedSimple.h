#pragma once

#include "Simple.h"

// Simple 클래스를 상속하는 클래스
class DerivedSimple : public Simple
{
public:
	DerivedSimple();                      // 생성자

	virtual void publicMethod() override; // 오버라이드한 메서드
	virtual void anotherMethod();         // 새로 추가한 메서드
};
