#include <stdexcept>
#include <iostream>

void throwIf(bool throwIt)
{
	if (throwIt) {
		throw std::runtime_error("Here's my exception");
	}
}

int main()
{
	try {
		throwIf(false); // 익셉션을 던지지 않는다.
		throwIf(true);  // 익셉션을 던진다.
	} catch (const std::runtime_error& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
