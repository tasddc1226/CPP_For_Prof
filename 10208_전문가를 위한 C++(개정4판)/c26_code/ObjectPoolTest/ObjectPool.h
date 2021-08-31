#pragma once

#include <queue>
#include <memory>

// 디폴트 생성자가 있는 모든 클래스에서 사용할 수 있는 객체 풀
//
// acquireObject()는 사용 가능 상태에 있는 객체를 리턴한다.
// 사용할 객체가 남아 있지 않다면 새 인스턴스를 생성한다.
// 풀은 커지기만 할 뿐 줄어들지 않는다.
// 다시 말해 풀이 제거되기 전에는 그 안에 있는 객체를 제거하지 않는다.
// acquireObject()는 커스텀 딜리터가 있는 std::shared_ptr 객체를 리턴한다.
// 그래서 shared_ptr가 제거될 때 레퍼런스 카운트가 0에 도달하면 자동으로 풀에 반환된다.
//
// 풀에 있는 객체의 생성자와 소멸자는 객체를 사용할 때마다 호출되지 않고,
// 풀이 생성돼 제거될 때까지 단 한 번씩만 호출된다.
//
// 객체 풀은 주로 여러 객체를 반복적으로 생성하고 삭제하지 않게 하는 용도로 사용된다.
// 여기서 제공하는 객체 풀은 객체의 생성자를 짧은 기간에 실행하기에는 부담이 많으면서
// 프로파일러도 이런 객체를 생성하고 삭제하는 부분이 성능 병목점이라고 지적한 경우에 적용하면 좋다.

template <typename T>
class ObjectPool
{
public:
	ObjectPool() = default;
	virtual ~ObjectPool() = default;

	// 대입과 값 전달 방식을 막는다.
	ObjectPool(const ObjectPool<T>& src) = delete;
	ObjectPool<T>& operator=(const ObjectPool<T>& rhs) = delete;

	// acquireObject()가 리턴하는 스마트 포인터 타입
	using Object = std::shared_ptr<T>;

	// 사용할 객체를 보관하고 제공한다.
	Object acquireObject();

private:
	// 현재 사용되지 않는 객체를 저장한다.
	std::queue<std::unique_ptr<T>> mFreeList;
};

template <typename T>
typename ObjectPool<T>::Object ObjectPool<T>::acquireObject()
{
	if (mFreeList.empty()) {
		mFreeList.emplace(std::make_unique<T>());
	}

	// 다음 차례에 제공할 가용 객체를 큐에서 빼서 로컬 unique_ptr로 옮긴다.
	std::unique_ptr<T> obj(std::move(mFreeList.front()));
	mFreeList.pop();

	// 객체 포인터를 Object(커스텀 딜리터를 갖춘 shared_ptr)로 변환한다.
	Object smartObject(obj.release(), [this](T* t) {
		// 커스텀 딜리터는 메모리를 직접 해제하지 않고,
		// 객체를 풀에 반환하기만 한다.
		mFreeList.emplace(t);
	});

	// 객체를 리턴한다.
	return smartObject;
}
