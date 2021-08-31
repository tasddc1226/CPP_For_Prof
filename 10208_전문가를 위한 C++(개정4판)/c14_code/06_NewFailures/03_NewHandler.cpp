#include <cstddef>
#include <new>
#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

class please_terminate_me : public bad_alloc { };

void myNewHandler()
{
	cerr << "Unable to allocate memory." << endl;
	throw please_terminate_me();
}

int main()
{
	try {
		// 새로 만든 new 핸들러를 설정하고 예전 것은 저장해둔다.
		new_handler oldHandler = set_new_handler(myNewHandler);

		// 할당 에러를 발생시킨다.
		size_t numInts = numeric_limits<size_t>::max();
		int* ptr = new int[numInts];

		// 예전 new 핸들러로 되돌린다.
		set_new_handler(oldHandler);
	} catch (const please_terminate_me&) {
		cerr << __FILE__ << "(" << __LINE__
			<< "): Terminating program." << endl;
		return 1;
	}
	return 0;
}
