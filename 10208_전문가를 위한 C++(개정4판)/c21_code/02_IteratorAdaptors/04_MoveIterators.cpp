#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

class MoveableClass
{
public:
	MoveableClass() {
		cout << "Default constructor" << endl;
	}
	MoveableClass(const MoveableClass& /* src */) {
		cout << "Copy constructor" << endl;
	}
	MoveableClass(MoveableClass&& /* src */) noexcept {
		cout << "Move constructor" << endl;
	}
	MoveableClass& operator=(const MoveableClass& /* rhs */) {
		cout << "Copy assignment operator" << endl;
		return *this;
	}
	MoveableClass& operator=(MoveableClass&& /* rhs */) noexcept {
		cout << "Move assignment operator" << endl;
		return *this;
	}
};

int main()
{
	vector<MoveableClass> vecSource;
	MoveableClass mc;
	vecSource.push_back(mc);
	vecSource.push_back(mc);
	cout << "----" << endl;

	// vecSource�� ���Ҹ� vecOne���� �̵��Ѵ�.
	vector<MoveableClass> vecOne(cbegin(vecSource), cend(vecSource));
	cout << "----" << endl;
	
	// vecSource�� ���Ҹ� vecTwo�� �̵��Ѵ�.
	vector<MoveableClass> vecTwo(make_move_iterator(begin(vecSource)),
								 make_move_iterator(end(vecSource)));

	// C++17�� �����ڿ� ���� ���ø� �μ� �߷� ����� ������ �ڵ�
	//vector<MoveableClass> vecTwo(move_iterator(begin(vecSource)),
	//							 move_iterator(end(vecSource)));

	cout << "----" << endl;

	return 0;
}
