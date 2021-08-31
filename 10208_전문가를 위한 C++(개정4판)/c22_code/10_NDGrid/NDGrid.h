#pragma once

#include <cstddef>
#include <vector>

template <typename T, size_t N>
class NDGrid
{
public:
	explicit NDGrid(size_t size = kDefaultSize);
	virtual ~NDGrid() = default;

	NDGrid<T, N-1>& operator[](size_t x);
	const NDGrid<T, N-1>& operator[](size_t x) const;

	void resize(size_t newSize);
	size_t getSize() const { return mElements.size(); }

	static const size_t kDefaultSize = 10;

private:
	std::vector<NDGrid<T, N-1>> mElements;
};

template <typename T>
class NDGrid<T, 1>
{
public:
	explicit NDGrid(size_t size = kDefaultSize);
	virtual ~NDGrid() = default;

	T& operator[](size_t x);
	const T& operator[](size_t x) const;

	void resize(size_t newSize);
	size_t getSize() const { return mElements.size(); }

	static const size_t kDefaultSize = 10;

private:
	std::vector<T> mElements;
};

template <typename T, size_t N>
NDGrid<T, N>::NDGrid(size_t size)
{
	resize(size);
}

template <typename T, size_t N>
void NDGrid<T, N>::resize(size_t newSize)
{
	mElements.resize(newSize);

	// vector에 대해 resize()를 호출하면 NDGrid<T, N-1> 원소에 대한 영인수 생성자를 호출해서
	// 디폴트 크기로 원소가 생성된다. 따라서 각 원소마다 명시적으로 resize()를 재귀 호출하는 방식으로
	// 중첩된 Grid 원소의 크기를 조정한다.
	for (auto& element : mElements) {
		element.resize(newSize);
	}
}

template <typename T, size_t N>
NDGrid<T, N-1>& NDGrid<T, N>::operator[](size_t x)
{
	return mElements[x];
}

template <typename T, size_t N>
const NDGrid<T, N-1>& NDGrid<T, N>::operator[](size_t x) const
{
	return mElements[x];
}


////////////////////////


template <typename T>
NDGrid<T, 1>::NDGrid(size_t size)
{
	resize(size);
}

template <typename T>
void NDGrid<T, 1>::resize(size_t newSize)
{
	mElements.resize(newSize);
}

template <typename T>
T& NDGrid<T, 1>::operator[](size_t x)
{
	return mElements[x];
}

template <typename T>
const T& NDGrid<T, 1>::operator[](size_t x) const
{
	return mElements[x];
}
