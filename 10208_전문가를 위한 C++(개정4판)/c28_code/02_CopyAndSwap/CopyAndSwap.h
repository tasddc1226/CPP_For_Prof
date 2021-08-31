#pragma once

// ���� �� �¹ٲٱ� ������ �����ֱ� ���� ������ Ŭ����
class CopyAndSwap
{
public:
	CopyAndSwap() = default;
	virtual ~CopyAndSwap();                         // ���� �Ҹ���

	CopyAndSwap(const CopyAndSwap& src);            // ���� ������
	CopyAndSwap& operator=(const CopyAndSwap& rhs); // ���� ������

	friend void swap(CopyAndSwap& first, CopyAndSwap& second) noexcept;

private:
	// private ������ ���
};
