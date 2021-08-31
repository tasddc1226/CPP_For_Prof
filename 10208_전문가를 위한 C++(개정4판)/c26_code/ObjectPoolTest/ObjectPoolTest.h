#pragma once

#include <CppUnitTest.h>

TEST_CLASS(ObjectPoolTest)
{
public:
	TEST_CLASS_INITIALIZE(setUp);
	TEST_CLASS_CLEANUP(tearDown);

	TEST_METHOD(testSimple);  // 첫 번째 테스트 예제
	TEST_METHOD(testException);

	TEST_METHOD(testCreation);
	TEST_METHOD(testAcquire);
	TEST_METHOD(testExclusivity);
	TEST_METHOD(testRelease);
};
