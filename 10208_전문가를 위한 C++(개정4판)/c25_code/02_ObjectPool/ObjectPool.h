#pragma once

#include <queue>
#include <memory>

// ����Ʈ �����ڰ� �ִ� ��� Ŭ�������� ����� �� �ִ� ��ü Ǯ
//
// acquireObject()�� ��� ���� ���¿� �ִ� ��ü�� �����Ѵ�.
// ����� ��ü�� ���� ���� �ʴٸ� �� �ν��Ͻ��� �����Ѵ�.
// Ǯ�� Ŀ���⸸ �� �� �پ���� �ʴ´�.
// �ٽ� ���� Ǯ�� ���ŵǱ� ������ �� �ȿ� �ִ� ��ü�� �������� �ʴ´�.
// acquireObject()�� Ŀ���� �����Ͱ� �ִ� std::shared_ptr ��ü�� �����Ѵ�.
// �׷��� shared_ptr�� ���ŵ� �� ���۷��� ī��Ʈ�� 0�� �����ϸ� �ڵ����� Ǯ�� ��ȯ�ȴ�.
//
// Ǯ�� �ִ� ��ü�� �����ڿ� �Ҹ��ڴ� ��ü�� ����� ������ ȣ����� �ʰ�,
// Ǯ�� ������ ���ŵ� ������ �� �� ������ ȣ��ȴ�.
//
// ��ü Ǯ�� �ַ� ���� ��ü�� �ݺ������� �����ϰ� �������� �ʰ� �ϴ� �뵵�� ���ȴ�.
// ���⼭ �����ϴ� ��ü Ǯ�� ��ü�� �����ڸ� ª�� �Ⱓ�� �����ϱ⿡�� �δ��� �����鼭
// �������Ϸ��� �̷� ��ü�� �����ϰ� �����ϴ� �κ��� ���� �������̶�� ������ ��쿡 �����ϸ� ����.

template <typename T>
class ObjectPool
{
public:
	ObjectPool() = default;
	virtual ~ObjectPool() = default;

	// ���԰� �� ���� ����� ���´�.
	ObjectPool(const ObjectPool<T>& src) = delete;
	ObjectPool<T>& operator=(const ObjectPool<T>& rhs) = delete;

	// acquireObject()�� �����ϴ� ����Ʈ ������ Ÿ��
	using Object = std::shared_ptr<T>;

	// ����� ��ü�� �����ϰ� �����Ѵ�.
	Object acquireObject();

private:
	// ���� ������ �ʴ� ��ü�� �����Ѵ�.
	std::queue<std::unique_ptr<T>> mFreeList;
};

template <typename T>
typename ObjectPool<T>::Object ObjectPool<T>::acquireObject()
{
	if (mFreeList.empty()) {
		mFreeList.emplace(std::make_unique<T>());
	}

	// ���� ���ʿ� ������ ���� ��ü�� ť���� ���� ���� unique_ptr�� �ű��.
	std::unique_ptr<T> obj(std::move(mFreeList.front()));
	mFreeList.pop();

	// ��ü �����͸� Object(Ŀ���� �����͸� ���� shared_ptr)�� ��ȯ�Ѵ�.
	Object smartObject(obj.release(), [this](T* t){
		// Ŀ���� �����ʹ� �޸𸮸� ���� �������� �ʰ�,
		// ��ü�� Ǯ�� ��ȯ�ϱ⸸ �Ѵ�.
		mFreeList.emplace(t);
	});

	// ��ü�� �����Ѵ�.
	return smartObject;
}
