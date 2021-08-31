#pragma once

// 복제 후 맞바꾸기 패턴을 보여주기 위한 간단한 클래스
class CopyAndSwap
{
public:
	CopyAndSwap() = default;
	virtual ~CopyAndSwap();                         // 가상 소멸자

	CopyAndSwap(const CopyAndSwap& src);            // 복제 생성자
	CopyAndSwap& operator=(const CopyAndSwap& rhs); // 대입 연산자

	friend void swap(CopyAndSwap& first, CopyAndSwap& second) noexcept;

private:
	// private 데이터 멤버
};
