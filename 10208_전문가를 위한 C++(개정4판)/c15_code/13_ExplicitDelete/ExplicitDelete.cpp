#include <new>
#include <cstddef>

class MyClass
{
public:
	void* operator new(size_t size) = delete;
	void* operator new[](size_t size) = delete;
};

int main()
{
	// MyClass �ν��Ͻ��� ���ÿ� ������ ���� �ִ�.
	MyClass classOnStack;

	// MyClass �ν��Ͻ��� ���� ������ ���� ����.
	// ������ ���� �ۼ��ϸ� ������ ������ �߻��Ѵ�.
	//MyClass* p1 = new MyClass;
	//MyClass* pArray = new MyClass[2];

	return 0;
}
