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

	// vecSource의 원소를 vecOne으로 이동한다.
	vector<MoveableClass> vecOne(cbegin(vecSource), cend(vecSource));
	cout << "----" << endl;
	
	// vecSource의 원소를 vecTwo로 이동한다.
	vector<MoveableClass> vecTwo(make_move_iterator(begin(vecSource)),
								 make_move_iterator(end(vecSource)));

	// C++17의 생성자에 대한 템플릿 인수 추론 기능을 적용한 코드
	//vector<MoveableClass> vecTwo(move_iterator(begin(vecSource)),
	//							 move_iterator(end(vecSource)));

	cout << "----" << endl;

	return 0;
}
