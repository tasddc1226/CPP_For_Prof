#include "CarFactory.h"
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

using namespace std;

class LeastBusyFactory : public CarFactory
{
public:
	// 여러 공장을 갖는 LeastBusyFactory 인스턴스를 생성한다.
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

	// 포드 공장 세 개와 도요타 공장 하나를 생성한다. 
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<ToyotaFactory>());

	// 그럴 듯한 결과를 얻도록 자동차 몇 대를 주문한다.
	factories[0]->requestCar();
	factories[0]->requestCar();
	factories[1]->requestCar();
	factories[3]->requestCar();

	// 전달된 공장 목록 중에서 가장 여유 있는 공장을 알아서 선택하는 팩토리 객체를 생성한다.
	LeastBusyFactory leastBusyFactory(std::move(factories));

	// 가장 여유 있는 공장에서 자동차 10대를 제조한다.
	for (size_t i = 0; i < 10; i++) {
		auto theCar = leastBusyFactory.requestCar();
		cout << theCar->info() << endl;
	}

	return 0;
}
