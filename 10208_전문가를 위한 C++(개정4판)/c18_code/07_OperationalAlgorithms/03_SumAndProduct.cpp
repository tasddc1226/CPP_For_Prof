#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

// int 타입 컨테이너에 원소를 채우는 함수 템플릿
// 이때 컨테이너는 반드시 push_back()을 제공해야 한다.
template<typename Container>
void populateContainer(Container& cont)
{
	int num;

	while (true) {
		cout << "Enter a number (0 to quit): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		cont.push_back(num);
	}
}

class SumAndProduct
{
public:
	void operator()(int value);
	int getSum() const { return mSum; }
	int getProduct() const { return mProduct; }

private:
	int mSum = 0;
	int mProduct = 1;
};

void SumAndProduct::operator()(int value)
{
	mSum += value;
	mProduct *= value;
}

int main()
{
	vector<int> myVector;
	populateContainer(myVector);

	SumAndProduct func;
	func = for_each(cbegin(myVector), cend(myVector), func);
	cout << "The sum is " << func.getSum() << endl;
	cout << "The product is " << func.getProduct() << endl;

	return 0;
}
