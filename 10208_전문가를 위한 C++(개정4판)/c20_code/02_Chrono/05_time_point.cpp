#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	// 연계된 steady_clock에 대한 에포크를 표현하는 time_point를 생성한다.
	time_point<steady_clock> tp1;
	// 또는 다음과 같이 작성한다.
	// steady_clock::time_point tp1;

	// 이 time_point에 10분을 더한다.
	tp1 += minutes(10);
	// 에포크와 time_point 사이의 duration을 저장한다.
	auto d1 = tp1.time_since_epoch();
	// duration을 초 단위로 변환해서 결과를 콘솔에 출력한다.
	duration<double> d2(d1);
	cout << d2.count() << " seconds" << endl;

	return 0;
}
