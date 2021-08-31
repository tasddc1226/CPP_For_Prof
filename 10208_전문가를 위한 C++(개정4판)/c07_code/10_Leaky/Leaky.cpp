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
	outSimplePtr = new Simple(); // ����! ���� ��ü�� �������� �ʾҴ�.
}

int main()
{
	Simple* simplePtr = new Simple(); // Simple ��ü �ϳ��� �Ҵ��Ѵ�.

	doSomething(simplePtr);

	delete simplePtr; // �� ��° ��ü�� �����Ѵ�.

	return 0;
}
