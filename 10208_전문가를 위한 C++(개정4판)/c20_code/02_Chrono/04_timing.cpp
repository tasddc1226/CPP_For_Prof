#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

int main()
{
	// 시작 시각을 가져온다.
	auto start = high_resolution_clock::now();
	
	// 시간을 재고 싶은 코드를 실행한다.
	
	double d = 0;
	for (int i = 0; i < 1000000; ++i) {
		d += sqrt(sin(i) * cos(i));
	}
	// 끝 시간을 구해서 시작 시간과의 차를 구한다.
	auto end = high_resolution_clock::now();
	auto diff = end - start;
	// 구한 시간 차를 ms 단위로 변환해서 콘솔에 출력한다.
	cout << duration<double, milli>(diff).count() << "ms" << endl;

	// d를 출력한다. 그렇지 않으면 앞에 나온 반복문 전체를 컴파일러가 최적화해버릴 수 있다.
	cout << d << endl;

	return 0;
}
