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

	b = d; // 상속 계층을 올라갈 때는 캐스팅할 필요 없다.
	d = static_cast<Derived*>(b); // 상속 계층을 내려갈 때는 캐스팅해야 한다.

	Base base;
	Derived derived;

	Base& br = derived;
	Derived& dr = static_cast<Derived&>(br);

	return 0;
}
