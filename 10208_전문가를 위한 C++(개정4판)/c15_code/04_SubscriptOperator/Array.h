#pragma once

#include <cstddef>
#include <stdexcept>
#include <memory>

template <typename T>
class Array
{
public:
	// 필요에 따라 크기가 증가하는 배열을 디폴트 크기로 생성한다.
	Array();
	virtual ~Array();

	// 대입과 값 전달 방식을 허용하지 않는다.
	Array<T>& operator=(const Array<T>& rhs) = delete;
	Array(const Array<T>& src) = delete;

	T& operator[](size_t x);
	const T& operator[](size_t x) const;

	// 인덱스 x에 있는 값을 리턴한다. 인덱스 x 지점에 원소가 없으면
	// out_of_range 익셉션을 던진다.
	const T& getElementAt(size_t x) const;

	// 인덱스 x 지점에 값을 설정한다. 인덱스 x가 현재 배열의 크기를 벗어나면
	// 공간을 더 할당한다.
	void setElementAt(size_t x, const T& value);

	size_t getSize() const;

private:
	static const size_t kAllocSize = 4;
	void resize(size_t newSize);
	T* mElements = nullptr;
	size_t mSize = 0;
};

template <typename T>
Array<T>::Array()
{
	mSize = kAllocSize;
	mElements = new T[mSize] {}; // 원소를 0으로 초기화한다.
}

template <typename T>
Array<T>::~Array()
{
	delete [] mElements;
	mElements = nullptr;
}

template <typename T>
void Array<T>::resize(size_t newSize)
{
	// 더 큰 배열을 생성한다. 값은 0으로 초기화한다.
	auto newArray = std::make_unique<T[]>(newSize);

	// 새로 생성할 배열은 반드시 이전(mSize)보다 커야 한다.
	for (size_t i = 0; i < mSize; i++) {
		// 이전 배열의 원소를 모두 새 배열로 복사한다.
		newArray[i] = mElements[i];
	}

	// 이전 배열을 삭제하고 새 배열을 생성한다.
	delete[] mElements;
	mSize = newSize;
	mElements = newArray.release();
}

template <typename T>
T& Array<T>::operator[](size_t x)
{
	if (x >= mSize) {
		// 클라이언트가 요청한 원소 뒤로 kAllocSize만큼 공간을 할당한다.
		resize(x + kAllocSize);
	}
	return mElements[x];
}

template <typename T>
const T& Array<T>::operator[](size_t x) const
{
	if (x >= mSize) {
		throw std::out_of_range("");
	}
	return mElements[x];
}

/*
template <typename T>
const T& Array<T>::operator[](size_t x) const
{
	if (x >= mSize) {
		static T nullValue = T();
		return nullValue;
	}
	return mElements[x];
}
*/

template <typename T>
const T& Array<T>::getElementAt(size_t x) const
{
	if (x >= mSize) {
		throw std::out_of_range("");
	}
	return mElements[x];
}

template <typename T>
void Array<T>::setElementAt(size_t x, const T& val)
{
	if (x >= mSize) {
		// 클라이언트가 요청한 원소 뒤로 kAllocSize만큼 공간을 할당한다.
		resize(x + kAllocSize);
	}
	mElements[x] = val;
}

template <typename T>
size_t Array<T>::getSize() const
{
	return mSize;
}
