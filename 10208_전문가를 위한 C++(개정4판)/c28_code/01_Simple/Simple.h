#pragma once

// 클래스 정의 문법을 보여주기 위해 간단히 작성한 클래스
class Simple
{
public:
	Simple();                       // 생성자
	virtual ~Simple() = default;    // 디폴트로 지정한 가상 소멸자

	// 대입과 값 전달 방식 허용하지 않는다.
	Simple(const Simple& src) = delete;
	Simple& operator=(const Simple& rhs) = delete;

	// 이동 생성자와 이동 대입 연산자를 명시적으로 디폴트로 지정한다.
	Simple(Simple&& src) = default;
	Simple& operator=(Simple&& rhs) = default;

	virtual void publicMethod();    // public 메서드
	int mPublicInteger;             // public 데이터 멤버

protected:
	virtual void protectedMethod(); // protected 메서드
	int mProtectedInteger = 41;     // protected 데이터 멤버

private:
	virtual void privateMethod();   // private 메서드
	int mPrivateInteger = 42;       // private 데이터 멤버
	static const int kConstant = 2; // private 상수
	static int sStaticInt;          // private static 데이터 멤버
};
