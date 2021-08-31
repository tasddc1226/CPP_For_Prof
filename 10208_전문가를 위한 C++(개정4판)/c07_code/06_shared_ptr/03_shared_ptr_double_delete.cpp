#include <memory>
#include <iostream>

using namespace std;

class Simple
{
public:
	Simple() { cout << "Simple constructor called!" << endl; }
	~Simple() { cout << "Simple destructor called!" << endl; }
};

void doubleDelete()
{
	Simple* mySimple = new Simple();
	shared_ptr<Simple> smartPtr1(mySimple);
	shared_ptr<Simple> smartPtr2(mySimple);
}

void noDoubleDelete()
{
	auto smartPtr1 = make_shared<Simple>();
	shared_ptr<Simple> smartPtr2(smartPtr1);
}

int main()
{
	//doubleDelete();  // 버그, 프로그램이 뻗을 수 있다.
	noDoubleDelete();

	return 0;
}
