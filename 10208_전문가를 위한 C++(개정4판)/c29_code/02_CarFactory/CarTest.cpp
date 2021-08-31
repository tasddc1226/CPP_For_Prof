#include "CarFactory.h"
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

using namespace std;

class LeastBusyFactory : public CarFactory
{
public:
	// ���� ������ ���� LeastBusyFactory �ν��Ͻ��� �����Ѵ�.
	explicit LeastBusyFactory(vector<unique_ptr<CarFactory>>&& factories);

protected:
	virtual unique_ptr<Car> createCar() override;

private:
	vector<unique_ptr<CarFactory>> mFactories;
};

LeastBusyFactory::LeastBusyFactory(vector<unique_ptr<CarFactory>>&& factories)
	: mFactories(std::move(factories))
{
	if (mFactories.empty())
		throw runtime_error("No factories provided.");
}

unique_ptr<Car> LeastBusyFactory::createCar()
{
	CarFactory* bestSoFar = mFactories[0].get();

	for (auto& factory : mFactories) {
		if (factory->getNumberOfCarsProduced() <
			bestSoFar->getNumberOfCarsProduced()) {
			bestSoFar = factory.get();
		}
	}

	return bestSoFar->requestCar();
}

int main()
{
	ToyotaFactory myFactory;
	auto myCar = myFactory.requestCar();
	cout << myCar->info() << endl;    // Outputs Toyota

	cout << "------------" << endl;


	vector<unique_ptr<CarFactory>> factories;

	// ���� ���� �� ���� ����Ÿ ���� �ϳ��� �����Ѵ�. 
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<ToyotaFactory>());

	// �׷� ���� ����� �򵵷� �ڵ��� �� �븦 �ֹ��Ѵ�.
	factories[0]->requestCar();
	factories[0]->requestCar();
	factories[1]->requestCar();
	factories[3]->requestCar();

	// ���޵� ���� ��� �߿��� ���� ���� �ִ� ������ �˾Ƽ� �����ϴ� ���丮 ��ü�� �����Ѵ�.
	LeastBusyFactory leastBusyFactory(std::move(factories));

	// ���� ���� �ִ� ���忡�� �ڵ��� 10�븦 �����Ѵ�.
	for (size_t i = 0; i < 10; i++) {
		auto theCar = leastBusyFactory.requestCar();
		cout << theCar->info() << endl;
	}

	return 0;
}
