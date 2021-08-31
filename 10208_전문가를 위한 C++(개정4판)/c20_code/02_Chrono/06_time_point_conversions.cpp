#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	{
		time_point<steady_clock, seconds> tpSeconds(42s);
		// �Ϲ������� �� ������ ms ������ ��ȯ�Ѵ�.
		time_point<steady_clock, milliseconds> tpMilliseconds(tpSeconds);

		cout << tpMilliseconds.time_since_epoch().count() << " ms" << endl;
	}

	{
		time_point<steady_clock, milliseconds> tpMilliseconds(42'424ms);
		// ��������� �� ������ ms ������ ��ȯ�Ѵ�.
		time_point<steady_clock, seconds> tpSeconds(
			time_point_cast<seconds>(tpMilliseconds));

		// �ٽ� �� ������ ms ������ ��ȯ�ؼ� �ֿܼ� ����Ѵ�.
		milliseconds ms(tpSeconds.time_since_epoch());
		cout << ms.count() << " ms" << endl;
	}

	return 0;
}
