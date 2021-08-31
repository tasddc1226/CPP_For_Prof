#pragma once

// �� �������� Car Ŭ������ �̹� �����Ѵٰ� �����Ѵ�.
#include "Car.h"
#include <cstddef>
#include <memory>

class CarFactory
{
public:
	virtual ~CarFactory() = default;  // �׻� ���� �Ҹ��ڷ� �����Ѵ�.
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
