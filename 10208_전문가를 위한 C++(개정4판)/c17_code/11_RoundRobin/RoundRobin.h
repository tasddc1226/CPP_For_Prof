#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

// RoundRobin Ŭ���� ���ø�
// ����Ʈ�� ��� ���ҿ� ���� ������ ���� �κ� �����ٸ��� �����Ѵ�.
template <typename T>
class RoundRobin
{
public:
	// ȿ���� ���̱� ���� ������ ���� ������ Ŭ���̾�Ʈ�� �޴´�.
	RoundRobin(size_t numExpected = 0);
	virtual ~RoundRobin() = default;

	// ���԰� �� ������ �����Ѵ�.
	RoundRobin(const RoundRobin& src) = delete;
	RoundRobin& operator=(const RoundRobin& rhs) = delete;

	// �̵� �����ڿ� �̵� ���� �����ڸ� ��������� ����Ʈ�� �����Ѵ�.
	RoundRobin(RoundRobin&& src) = default;
	RoundRobin& operator=(RoundRobin&& rhs) = default;

	// ���Ҹ� ����Ʈ ���� �߰��Ѵ�.
	// getNext() ���̿� ȣ��� �� �ִ�.
	void add(const T& element);

	// operator== �����ڸ� ȣ���� ���,
	// �Ȱ��ٰ� �Ǵܵ� ù ��° ���Ҹ� �����Ѵ�.
	// getNext() ���̿� ȣ��� �� �ִ�.
	void remove(const T& element);

	// ����Ʈ�� ���� �� ���Ҹ� �����Ѵ�. ù ��° ���Һ��� �����ؼ� ������ 
	// ���ҿ� �ٴٸ��� �ٽ� ù ��° ���ҷ� ���ƿ´�. 
	// �̶� �߰��� �߰��ǰų� ������ ���ҵ� �ݿ��Ѵ�.
	T& getNext();

private:
	std::vector<T> mElements;
	typename std::vector<T>::iterator mCurrentElement;
};

template <typename T>
RoundRobin<T>::RoundRobin(size_t numExpected)
{
	// Ŭ���̾�Ʈ�� ������ ��ŭ ������ Ȯ���Ѵ�.
	mElements.reserve(numExpected);

	// ���Ұ� �ּ� �ϳ� ���� ������ ������� �ʴ���
	// �ϴ� mCurrentElement�� �ʱ�ȭ�صд�.
	// there's at least one element.
	mCurrentElement = begin(mElements);
}

// �� ���Ҵ� �׻� �������� �߰��Ѵ�.
template <typename T>
void RoundRobin<T>::add(const T& element)
{
	// ���Ҹ� �������� �߰��ϴ��� push_back()�� ȣ���� �����
	// vector�� ���Ҵ�Ǽ� mCurrentElement �ݺ��ڰ� ��ȿȭ�� �� �ִ�.
	// ������ �����Ϸ��� �ݺ����� ���� �׼��� ����� �ִ��� Ȱ���Ѵ�.
	// iterator features to save our spot.
	int pos = mCurrentElement - begin(mElements);

	// ���Ҹ� �߰��Ѵ�.
	mElements.push_back(element);
	
	// �ݺ��ڸ� �׻� ��ȿ�� ���·� �����ϵ��� �����Ѵ�.
	mCurrentElement = begin(mElements) + pos;
}

template <typename T>
void RoundRobin<T>::remove(const T& element)
{
	for (auto it = begin(mElements); it != end(mElements); ++it) {
		if (*it == element) {
			// mCurrentElement �ݺ��ڰ� �����ϴ� ���Ұ� ������ ����� ���� ���Ҹ�
			// ����Ű�� ���� �� ���Ҹ� �����ϸ� mCurrentElement �ݺ��ڰ� ��ȿȭ�ȴ�.
			// ������ �� ���� ������ ��ġ�� �����Ϸ���
			// �ݺ����� ���� �׼��� ����� Ȱ���Ѵ�.
			int newPos;

			if (mCurrentElement == end(mElements) - 1 &&
				mCurrentElement == it) {
				// mCurrentElement�� ����Ʈ�� ������ ���Ҹ� ����Ű�� ���¿���
				// �� ���Ҹ� �����Ϸ� �ϹǷ� �ٽ� ù ��° ���ҷ� ��ġ�� �̵���Ų��.
				// the beginning.
				newPos = 0;
			} else if (mCurrentElement <= it) {
				// O�׷��� �ʰ� mCurrentElement�� �����Ϸ��� ���ҳ� �� ���� ���Ҹ�
				// ����Ű�� �ִٸ� ��ġ�� ������ ����.
				newPos = mCurrentElement - begin(mElements);
			} else {
				// �տ� ���� �� ��� ��� �ش���� �ʴ´ٸ�
				// �� ĭ ���� �� ��ġ�� �ȴ�.
				newPos = mCurrentElement - begin(mElements) - 1;
			}

			// ���Ҹ� �����Ѵ�. (���ϰ��� �����Ѵ�.)
			mElements.erase(it);

			// �ݺ��ڰ� ��ȿ�� ���¸� �����ϵ��� �����Ѵ�.
			mCurrentElement = begin(mElements) + newPos;

			return;
		}
	}
}

template <typename T>
T& RoundRobin<T>::getNext()
{
	// ���� ���Ұ� ��� �ִ������� Ȯ���Ѵ�.
	if (mElements.empty()) {
		throw std::out_of_range("No elements in the list");
	}

	// ���� ����(������ ����)�� �����ϵ��� �����صд�.
	auto& toReturn = *mCurrentElement;

	// �ݺ��ڸ� ���� ���� ���� ����(modulo, ������) ������ �̿��Ͽ� ������Ų��.
	++mCurrentElement;
	if (mCurrentElement == end(mElements)) {
		mCurrentElement = begin(mElements);
	}

	// ���ҿ� ���� ���۷����� �����Ѵ�.
	return toReturn;
}
