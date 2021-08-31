#include "ObjectPool.h"
#include <cstddef>
#include <iostream>

using namespace std;

class ExpensiveObject
{
public:
	ExpensiveObject() { mID = ++msCount; cout << "ctor " << mID << endl; }
	virtual ~ExpensiveObject() { cout << "dtor " << mID << endl; }

	// ��ü�� Ư���� ������ ��� �޼���
	// ��ü �����͸� �������� �޼���
	// (�ڵ�� ����)

private:
	int mID;
	static int msCount;
	// �� ���� �ٸ� ������ ���(�ڵ�� ����)
};
int ExpensiveObject::msCount = 0;

ObjectPool<ExpensiveObject>::Object
    getExpensiveObject(ObjectPool<ExpensiveObject>& pool)
{
	// ExpensiveObject ��ü�� Ǯ���� �����´�.
	auto object = pool.acquireObject();

	// ��ü�� ������ ä���. (�ڵ�� ����)

	return object;
}

void processExpensiveObject(ObjectPool<ExpensiveObject>::Object& /*object*/)
{
	// ��ü�� ������ ó���Ѵ�. (�ڵ�� ����)
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
