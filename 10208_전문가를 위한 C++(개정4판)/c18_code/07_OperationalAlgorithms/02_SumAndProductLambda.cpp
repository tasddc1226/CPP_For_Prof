#include <algorithm>
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

int main()
{
	vector<int> myVector;
	populateContainer(myVector);

	int sum = 0;
	int product = 1;
	for_each(cbegin(myVector), cend(myVector),
		[&sum, &product](int i){
			sum += i;
			product *= i;
	});
	cout << "The sum is " << sum << endl;
	cout << "The product is " << product << endl;

	return 0;
}
