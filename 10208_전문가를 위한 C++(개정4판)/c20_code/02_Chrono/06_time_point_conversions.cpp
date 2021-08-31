#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	{
		time_point<steady_clock, seconds> tpSeconds(42s);
		// 암묵적으로 초 단위를 ms 단위로 변환한다.
		time_point<steady_clock, milliseconds> tpMilliseconds(tpSeconds);

		cout << tpMilliseconds.time_since_epoch().count() << " ms" << endl;
	}

	{
		time_point<steady_clock, milliseconds> tpMilliseconds(42'424ms);
		// 명시적으로 초 단위를 ms 단위로 변환한다.
		time_point<steady_clock, seconds> tpSeconds(
			time_point_cast<seconds>(tpMilliseconds));

		// 다시 초 단위를 ms 단위로 변환해서 콘솔에 출력한다.
		milliseconds ms(tpSeconds.time_since_epoch());
		cout << ms.count() << " ms" << endl;
	}

	return 0;
}
