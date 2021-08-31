#include "CarFactory.h"

// 제조한 자동차 수를 증가시키고 새 자동차 객체를 리턴한다.
std::unique_ptr<Car> CarFactory::requestCar()
{
	++mNumberOfCarsProduced;
	return createCar();
}

size_t CarFactory::getNumberOfCarsProduced() const
{
	return mNumberOfCarsProduced;
}

std::unique_ptr<Car> FordFactory::createCar()
{
	return std::make_unique<Ford>();
}

std::unique_ptr<Car> ToyotaFactory::createCar()
{
	return std::make_unique<Toyota>();
}
