#pragma once

// 이 예제에서 Car 클래스는 이미 존재한다고 가정한다.
#include "Car.h"
#include <cstddef>
#include <memory>

class CarFactory
{
public:
	virtual ~CarFactory() = default;  // 항상 가상 소멸자로 정의한다.
	std::unique_ptr<Car> requestCar();
	size_t getNumberOfCarsProduced() const;

protected:
	virtual std::unique_ptr<Car> createCar() = 0;

private:
	size_t mNumberOfCarsProduced = 0;
};

class FordFactory : public CarFactory
{
protected:
	virtual std::unique_ptr<Car> createCar() override;
};

class ToyotaFactory : public CarFactory
{
protected:
	virtual std::unique_ptr<Car> createCar() override;
};
