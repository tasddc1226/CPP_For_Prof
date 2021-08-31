#include "Simple.h"

int Simple::sStaticInt = 0;   // static 데이터 멤버 초기화

Simple::Simple() : mPublicInteger(40)
{
	// 생성자 구현 코드
}

void Simple::publicMethod() { /* public 메서드 구현 코드 */ }

void Simple::protectedMethod() { /* protected 메서드 구현 코드 */ }

void Simple::privateMethod() { /* private 메서드 구현 코드 */ }

int main()
{
	Simple mySimple;
	return 0;
}
