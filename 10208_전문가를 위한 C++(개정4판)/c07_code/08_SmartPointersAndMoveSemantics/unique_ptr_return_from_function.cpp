#include <iostream>
#include <memory>

using namespace std;

class Simple
{
public:
	Simple() { cout << "Simple constructor called!" << endl; }
	~Simple() { cout << "Simple destructor called!" << endl; }
};

unique_ptr<Simple> create()
{
	auto ptr = make_unique<Simple>();
	//  ptr�� ����ϴ� �ڵ带 ���⿡ �ۼ��Ѵ�.
	return ptr;
}

int main()
{
	unique_ptr<Simple> mySmartPtr1 = create();
	auto mySmartPtr2 = create();
	return 0;
}
