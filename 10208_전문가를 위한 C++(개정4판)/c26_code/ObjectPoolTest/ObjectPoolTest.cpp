#include "stdafx.h"
#include "ObjectPoolTest.h"
#include <stdexcept>
#include "ObjectPool.h" 
#include "Serial.h"
#include <cstddef>
#include <vector>
#include <set>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void ObjectPoolTest::setUp() { }
void ObjectPoolTest::tearDown() { }

void ObjectPoolTest::testSimple()
{
	Assert::IsTrue(0 < 1);
}

void ObjectPoolTest::testException()
{
	Assert::ExpectException<std::invalid_argument>(
		[]{throw std::invalid_argument("Error"); },
		L"Unknown exception caught.");
}

void ObjectPoolTest::testCreation()
{
	ObjectPool<Serial> myPool;
}

void ObjectPoolTest::testAcquire()
{
	ObjectPool<Serial> myPool;
	auto serial = myPool.acquireObject();
	Assert::IsTrue(serial->getSerialNumber() >= 0);
}

void ObjectPoolTest::testExclusivity()
{
	ObjectPool<Serial> myPool;
	const size_t numberOfObjectsToRetrieve = 10;
	std::vector<ObjectPool<Serial>::Object> retrievedSerials;
	std::set<size_t> seenSerialNumbers;

	for (size_t i = 0; i < numberOfObjectsToRetrieve; i++) {
		auto nextSerial = myPool.acquireObject();

		// ��ȸ�� Serial�� �����ϵ��� vector�� �߰��Ѵ�.
		// �Ϸù�ȣ�� set�� �����Ѵ�.
		retrievedSerials.push_back(nextSerial);
		seenSerialNumbers.insert(nextSerial->getSerialNumber());
	}

	// ��ȸ�� �Ϸù�ȣ�� ��� �ٸ��� Ȯ���ϴ� ���
	Assert::AreEqual(numberOfObjectsToRetrieve, seenSerialNumbers.size());
}

void ObjectPoolTest::testRelease()
{
	ObjectPool<Serial> myPool;
	const size_t numberOfObjectsToRetrieve = 10;

	std::vector<ObjectPool<Serial>::Object> retrievedSerials;
	for (size_t i = 0; i < numberOfObjectsToRetrieve; i++) {
		// ��ȸ�� �ø����� ���Ϳ� �����Ѵ�.
		retrievedSerials.push_back(myPool.acquireObject());
	}
	size_t lastSerialNumber = retrievedSerials.back()->getSerialNumber();
	// ��ü�� ��� Ǯ�� ��ȯ�Ѵ�.
	retrievedSerials.clear();

	// �տ� ���� �ݺ������� Serial ��ü�� �� �� �����ؼ� �Ϸù�ȣ�� 0���� 9���� �����.
	// �׷� ���� �� ���� Serial ��ü�� ��� Ǯ�� ��ȯ�Ѵ�.

	// ���� �ݺ����� ���� Serial ��ü�� �ٽ� �� �� �����´�.
	// ������ �Ϸù�ȣ�� lastSerialNumber���� �۰ų� ���ƾ� �Ѵ�.
	// �� �Ŀ� ������ Serial ��ü�� �Ϸù�ȣ�� ������ �ٸ� ���� ������ �Ѵ�.

	bool wronglyNewObjectCreated = false;
	for (size_t i = 0; i < numberOfObjectsToRetrieve; i++) {
		auto nextSerial = myPool.acquireObject();
		if (nextSerial->getSerialNumber() > lastSerialNumber) {
			wronglyNewObjectCreated = true;
			break;
		}
		retrievedSerials.push_back(nextSerial);
	}

	// Serial ��ü�� �ϳ� �̻� �����´�.
	// ������ ��ü�� �Ϸù�ȣ�� �ݵ�� lastSerialNumber���� Ŀ�� �Ѵ�.
	auto anotherSerial = myPool.acquireObject();
	bool newObjectCreated = (anotherSerial->getSerialNumber() > lastSerialNumber);

	Assert::IsFalse(wronglyNewObjectCreated);
	Assert::IsTrue(newObjectCreated);
}
