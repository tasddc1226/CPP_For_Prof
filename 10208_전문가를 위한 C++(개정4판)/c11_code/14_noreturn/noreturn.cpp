#include <cstdlib>
#include <iostream>

[[noreturn]] void forceProgramTermination()
{
	std::exit(1);
}

bool isDongleAvailable()
{
	bool isAvailable = false;
	// 라이센싱 동글을 사용할 수 있는지 확인한다.
	return isAvailable;
}

bool isFeatureLicensed(int /*featureId*/)
{
	if (!isDongleAvailable()) {
		// 라이센싱 동글을 발견하지 못했다면 프로그램을 중단한다.
		forceProgramTermination();
	} else {
		bool isLicensed = false;
		// 사용할 수 있는 동글이 있다면 주어진 기능에 대해 라이센스가 있는지 확인한다.
		return isLicensed;
	}
}

int main()
{
	bool isLicensed = isFeatureLicensed(42);
	std::cout << isLicensed << std::endl;
}