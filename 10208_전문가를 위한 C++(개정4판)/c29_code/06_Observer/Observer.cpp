#include <iostream>
#include <vector>
#include <algorithm>

class IObserver
{
public:
	virtual ~IObserver() = default;  // 항상 가상 소멸자로 정의한다.
	virtual void notify() = 0;
};

class ConcreteObserver1 : public IObserver
{
public:
	void notify() override { std::cout << "ConcreteObserver1::notify()" << std::endl; }
};

class ConcreteObserver2 : public IObserver
{
public:
	void notify() override { std::cout << "ConcreteObserver2::notify()" << std::endl; }
};



class Observable
{
public:
	virtual ~Observable() = default;  // 항상 가상 소멸자로 지정한다.

	// 옵저버를 추가한다. 소유권은 이전되지 않는다.
	void addObserver(IObserver* observer)
	{
		mObservers.push_back(observer);
	}

	// 지정한 옵저버를 제거한다.
	void removeObserver(IObserver* observer)
	{
		mObservers.erase(
			std::remove(begin(mObservers), end(mObservers), observer),
			end(mObservers));
	}

protected:
	void notifyAllObservers()
	{
		for (auto* observer : mObservers)
			observer->notify();
	}

private:
	std::vector<IObserver*> mObservers;
};



class ObservableSubject : public Observable
{
public:
	void modifyData()
	{
		// ...
		notifyAllObservers();
	}
};



int main()
{
	ObservableSubject subject;

	ConcreteObserver1 observer1;
	subject.addObserver(&observer1);

	subject.modifyData();

	std::cout << std::endl;

	ConcreteObserver2 observer2;
	subject.addObserver(&observer2);

	subject.modifyData();

	return 0;
}