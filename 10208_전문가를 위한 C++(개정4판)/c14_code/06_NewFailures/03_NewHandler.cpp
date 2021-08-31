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
		// ���� ���� new �ڵ鷯�� �����ϰ� ���� ���� �����صд�.
		new_handler oldHandler = set_new_handler(myNewHandler);

		// �Ҵ� ������ �߻���Ų��.
		size_t numInts = numeric_limits<size_t>::max();
		int* ptr = new int[numInts];

		// ���� new �ڵ鷯�� �ǵ�����.
		set_new_handler(oldHandler);
	} catch (const please_terminate_me&) {
		cerr << __FILE__ << "(" << __LINE__
			<< "): Terminating program." << endl;
		return 1;
	}
	return 0;
}
