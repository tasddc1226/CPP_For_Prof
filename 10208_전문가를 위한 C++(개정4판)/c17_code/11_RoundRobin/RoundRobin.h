#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

// RoundRobin 클래스 템플릿
// 리스트에 담긴 원소에 대해 간단한 라운드 로빈 스케줄링을 구현한다.
template <typename T>
class RoundRobin
{
public:
	// 효율을 높이기 위해 원소의 예상 갯수를 클라이언트로 받는다.
	RoundRobin(size_t numExpected = 0);
	virtual ~RoundRobin() = default;

	// 대입과 값 전달은 삭제한다.
	RoundRobin(const RoundRobin& src) = delete;
	RoundRobin& operator=(const RoundRobin& rhs) = delete;

	// 이동 생성자와 이동 대입 연산자를 명시적으로 디폴트로 지정한다.
	RoundRobin(RoundRobin&& src) = default;
	RoundRobin& operator=(RoundRobin&& rhs) = default;

	// 원소를 리스트 끝에 추가한다.
	// getNext() 사이에 호출될 수 있다.
	void add(const T& element);

	// operator== 연산자를 호출한 결과,
	// 똑같다고 판단된 첫 번째 원소만 삭제한다.
	// getNext() 사이에 호출될 수 있다.
	void remove(const T& element);

	// 리스트의 다음 번 원소를 리턴한다. 첫 번째 원소부터 시작해서 마지막 
	// 원소에 다다르면 다시 첫 번째 원소로 돌아온다. 
	// 이때 중간에 추가되거나 삭제된 원소도 반영한다.
	T& getNext();

private:
	std::vector<T> mElements;
	typename std::vector<T>::iterator mCurrentElement;
};

template <typename T>
RoundRobin<T>::RoundRobin(size_t numExpected)
{
	// 클라이언트가 지정한 만큼 공간을 확보한다.
	mElements.reserve(numExpected);

	// 원소가 최소 하나 있을 때까지 사용하지 않더라도
	// 일단 mCurrentElement를 초기화해둔다.
	// there's at least one element.
	mCurrentElement = begin(mElements);
}

// 새 원소는 항상 마지막에 추가한다.
template <typename T>
void RoundRobin<T>::add(const T& element)
{
	// 원소를 마지막에 추가하더라도 push_back()을 호출한 결과로
	// vector를 재할당되서 mCurrentElement 반복자가 무효화될 수 있다.
	// 공간을 절약하려면 반복자의 랜덤 액세스 기능을 최대한 활용한다.
	// iterator features to save our spot.
	int pos = mCurrentElement - begin(mElements);

	// 원소를 추가한다.
	mElements.push_back(element);
	
	// 반복자를 항상 유효한 상태로 유지하도록 리셋한다.
	mCurrentElement = begin(mElements) + pos;
}

template <typename T>
void RoundRobin<T>::remove(const T& element)
{
	for (auto it = begin(mElements); it != end(mElements); ++it) {
		if (*it == element) {
			// mCurrentElement 반복자가 참조하는 원소가 삭제할 대상의 다음 원소를
			// 가리키고 있을 때 원소를 삭제하면 mCurrentElement 반복자가 무효화된다.
			// 삭제한 후 현재 원소의 위치를 관리하려면
			// 반복자의 랜덤 액세스 기능을 활용한다.
			int newPos;

			if (mCurrentElement == end(mElements) - 1 &&
				mCurrentElement == it) {
				// mCurrentElement가 리스트의 마지막 원소를 가리키는 상태에서
				// 그 원소를 삭제하려 하므로 다시 첫 번째 원소로 위치를 이동시킨다.
				// the beginning.
				newPos = 0;
			} else if (mCurrentElement <= it) {
				// O그렇지 않고 mCurrentElement가 삭제하려는 원소나 그 앞의 원소를
				// 가리키고 있다면 위치는 이전과 같다.
				newPos = mCurrentElement - begin(mElements);
			} else {
				// 앞에 나온 두 경우 모두 해당되지 않는다면
				// 한 칸 앞이 새 위치가 된다.
				newPos = mCurrentElement - begin(mElements) - 1;
			}

			// 원소를 삭제한다. (리턴값은 무시한다.)
			mElements.erase(it);

			// 반복자가 유효한 상태를 유지하도록 리셋한다.
			mCurrentElement = begin(mElements) + newPos;

			return;
		}
	}
}

template <typename T>
T& RoundRobin<T>::getNext()
{
	// 먼저 원소가 담겨 있는지부터 확인한다.
	if (mElements.empty()) {
		throw std::out_of_range("No elements in the list");
	}

	// 현재 원소(삭제할 원소)를 리턴하도록 저장해둔다.
	auto& toReturn = *mCurrentElement;

	// 반복자를 원소 수에 대한 모듈로(modulo, 나머지) 연산을 이용하여 증가시킨다.
	++mCurrentElement;
	if (mCurrentElement == end(mElements)) {
		mCurrentElement = begin(mElements);
	}

	// 원소에 대한 레퍼런스를 리턴한다.
	return toReturn;
}
