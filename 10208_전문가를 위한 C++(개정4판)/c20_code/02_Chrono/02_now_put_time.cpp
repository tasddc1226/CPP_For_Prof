#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

using namespace std;
using namespace std::chrono;

int main()
{
	// 현재 시각을 time_point 타입으로 가져온다.
	system_clock::time_point tpoint = system_clock::now();

	// time_t 값으로 변환한다.
	time_t tt = system_clock::to_time_t(tpoint);

	// 현지 시각으로 변환한다.
	tm* t = localtime(&tt);
	// 최종 시각을 콘솔에 출력한다.
	cout << put_time(t, "%H:%M:%S") << endl;

	// 앞에서 localtime()을 호출하는 부분에서 보안 경고나 에러가 발생할 수 있다.
	// 마이크로소프트 비주얼 C++에서는 안전한 버전인 localtime_s()를 호출하도록, 
	// 리눅스라면 localtime_r()을 호출하도록 수정한다.
	// 예를 들어 Visual C++을 사용할 때는 위 문장을 다음과 같이 작성한다.
	//// 현지 시각으로 변환한다.
	//tm t;
	//localtime_s(&t, &tt);
	//// 최종 시각을 콘솔에 출력한다.
	//cout << put_time(&t, "%H:%M:%S") << endl;

	return 0;
}
