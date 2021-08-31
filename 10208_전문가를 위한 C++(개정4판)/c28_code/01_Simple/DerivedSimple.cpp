#include "DerivedSimple.h"

DerivedSimple::DerivedSimple() : Simple() 
{
	// 생성자 구현 코드
}

void DerivedSimple::publicMethod()
{
	// 오버라이드한 메서드의 구현 코드
	Simple::publicMethod(); // 베이스 클래스에 접근할 수 있다.
}

void DerivedSimple::anotherMethod()
{
	// 새로 추가한 메서드의 구현 코드
}
