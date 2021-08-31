#include "ObjectPool.h"
#include <cstddef>
#include <iostream>

using namespace std;

class ExpensiveObject
{
public:
	ExpensiveObject() { mID = ++msCount; cout << "ctor " << mID << endl; }
	virtual ~ExpensiveObject() { cout << "dtor " << mID << endl; }

	// 객체에 특정한 정보를 담는 메서드
	// 객체 데이터를 가져오는 메서드
	// (코드는 생략)

private:
	int mID;
	static int msCount;
	// 그 밖의 다른 데이터 멤버(코드는 생략)
};
int ExpensiveObject::msCount = 0;

ObjectPool<ExpensiveObject>::Object
    getExpensiveObject(ObjectPool<ExpensiveObject>& pool)
{
	// ExpensiveObject 객체를 풀에서 가져온다.
	auto object = pool.acquireObject();

	// 객체의 내용을 채운다. (코드는 생략)

	return object;
}

void processExpensiveObject(ObjectPool<ExpensiveObject>::Object& /*object*/)
{
	// 객체를 적절히 처리한다. (코드는 생략)
}

int main()
{
	ObjectPool<ExpensiveObject> requestPool;

	{
		vector<ObjectPool<ExpensiveObject>::Object> objects;
		for (size_t i = 0; i < 10; ++i) {
			objects.push_back(getExpensiveObject(requestPool));
		}
	}

	cout << "Loop starting." << endl;
	for (size_t i = 0; i < 100; ++i) {
		auto req = getExpensiveObject(requestPool);
		processExpensiveObject(req);
	}
	cout << "Loop finished." << endl;

	return 0;
}
