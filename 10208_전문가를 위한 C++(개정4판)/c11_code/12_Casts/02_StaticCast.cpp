class Base
{
public:
	virtual ~Base() = default;
};

class Derived : public Base
{
public:
	virtual ~Derived() = default;
};

int main()
{
	int i = 3;
	int j = 4;
	double result = static_cast<double>(i) / j;


	Base* b;
	Derived* d = new Derived();

	b = d; // ��� ������ �ö� ���� ĳ������ �ʿ� ����.
	d = static_cast<Derived*>(b); // ��� ������ ������ ���� ĳ�����ؾ� �Ѵ�.

	Base base;
	Derived derived;

	Base& br = derived;
	Derived& dr = static_cast<Derived&>(br);

	return 0;
}
