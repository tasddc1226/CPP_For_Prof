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
	// MyClass 인스턴스를 스택에 생성할 수도 있다.
	MyClass classOnStack;

	// MyClass 인스턴스를 힙에 생성할 수는 없다.
	// 다음과 같이 작성하면 컴파일 에러가 발생한다.
	//MyClass* p1 = new MyClass;
	//MyClass* pArray = new MyClass[2];

	return 0;
}
