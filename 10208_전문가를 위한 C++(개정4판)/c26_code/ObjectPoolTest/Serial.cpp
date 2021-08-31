#include "stdafx.h"
#include "Serial.h"

size_t Serial::sNextSerial = 0;  // 일련번호는 0부터 시작한다.

Serial::Serial()
	: mSerialNumber(sNextSerial++) // 새 객체에 다음번 일련번호를 지정한다.
{
}

size_t Serial::getSerialNumber() const
{
	return mSerialNumber;
}
