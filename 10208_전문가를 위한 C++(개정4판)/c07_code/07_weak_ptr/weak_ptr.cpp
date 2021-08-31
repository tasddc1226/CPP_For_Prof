#include <memory>
#include <iostream>

using namespace std;

class Simple
{
public:
	Simple() { cout << "Simple constructor called!" << endl; }
	~Simple() { cout << "Simple destructor called!" << endl; }
};

void useResource(weak_ptr<Simple>& weakSimple)
{
	auto resource = weakSimple.lock();
	if (resource) {
		cout << "Resource still alive." << endl;
	} else {
		cout << "Resource has been freed!" << endl;
	}
}

int main()
{
	auto sharedSimple = make_shared<Simple>();
	weak_ptr<Simple> weakSimple(sharedSimple);

	// weak_ptr를 사용한다.
	useResource(weakSimple);

	// shared_ptr를 리셋한다.
	// Simple 리소스에는 shared_ptr가 하나 뿐이므로
	// weak_ptr가 남아 있더라도 이렇게 하면 리소스를 해제한다. 
	sharedSimple.reset();

	// weak_ptr를 다시 한 번 사용한다.
	useResource(weakSimple);

    return 0;
}
