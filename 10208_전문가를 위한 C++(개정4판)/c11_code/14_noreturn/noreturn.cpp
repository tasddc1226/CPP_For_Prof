#include <cstdlib>
#include <iostream>

[[noreturn]] void forceProgramTermination()
{
	std::exit(1);
}

bool isDongleAvailable()
{
	bool isAvailable = false;
	// ���̼��� ������ ����� �� �ִ��� Ȯ���Ѵ�.
	return isAvailable;
}

bool isFeatureLicensed(int /*featureId*/)
{
	if (!isDongleAvailable()) {
		// ���̼��� ������ �߰����� ���ߴٸ� ���α׷��� �ߴ��Ѵ�.
		forceProgramTermination();
	} else {
		bool isLicensed = false;
		// ����� �� �ִ� ������ �ִٸ� �־��� ��ɿ� ���� ���̼����� �ִ��� Ȯ���Ѵ�.
		return isLicensed;
	}
}

int main()
{
	bool isLicensed = isFeatureLicensed(42);
	std::cout << isLicensed << std::endl;
}