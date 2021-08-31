class Simple 
{
public:
	Simple() { mIntPtr = new int(); }
	~Simple() { delete mIntPtr; }

	void setValue(int value) { *mIntPtr = value; }

private:
	int* mIntPtr;
};

void doSomething(Simple*& outSimplePtr)
{
	outSimplePtr = new Simple(); // 버그! 원본 객체를 삭제하지 않았다.
}

int main()
{
	Simple* simplePtr = new Simple(); // Simple 객체 하나를 할당한다.

	doSomething(simplePtr);

	delete simplePtr; // 두 번째 객체만 해제한다.

	return 0;
}
