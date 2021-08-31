#pragma once

// Ŭ���� ���� ������ �����ֱ� ���� ������ �ۼ��� Ŭ����
class Simple
{
public:
	Simple();                       // ������
	virtual ~Simple() = default;    // ����Ʈ�� ������ ���� �Ҹ���

	// ���԰� �� ���� ��� ������� �ʴ´�.
	Simple(const Simple& src) = delete;
	Simple& operator=(const Simple& rhs) = delete;

	// �̵� �����ڿ� �̵� ���� �����ڸ� ��������� ����Ʈ�� �����Ѵ�.
	Simple(Simple&& src) = default;
	Simple& operator=(Simple&& rhs) = default;

	virtual void publicMethod();    // public �޼���
	int mPublicInteger;             // public ������ ���

protected:
	virtual void protectedMethod(); // protected �޼���
	int mProtectedInteger = 41;     // protected ������ ���

private:
	virtual void privateMethod();   // private �޼���
	int mPrivateInteger = 42;       // private ������ ���
	static const int kConstant = 2; // private ���
	static int sStaticInt;          // private static ������ ���
};
