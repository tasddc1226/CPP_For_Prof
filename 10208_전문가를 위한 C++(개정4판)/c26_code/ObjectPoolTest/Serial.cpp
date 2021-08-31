#include "stdafx.h"
#include "Serial.h"

size_t Serial::sNextSerial = 0;  // �Ϸù�ȣ�� 0���� �����Ѵ�.

Serial::Serial()
	: mSerialNumber(sNextSerial++) // �� ��ü�� ������ �Ϸù�ȣ�� �����Ѵ�.
{
}

size_t Serial::getSerialNumber() const
{
	return mSerialNumber;
}
