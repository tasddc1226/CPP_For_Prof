#pragma once

#include <cstddef>
#include <stdexcept>
#include <memory>

template <typename T>
class Array
{
public:
	// �ʿ信 ���� ũ�Ⱑ �����ϴ� �迭�� ����Ʈ ũ��� �����Ѵ�.
	Array();
	virtual ~Array();

	// ���԰� �� ���� ����� ������� �ʴ´�.
	Array<T>& operator=(const Array<T>& rhs) = delete;
	Array(const Array<T>& src) = delete;

	T& operator[](size_t x);
	const T& operator[](size_t x) const;

	// �ε��� x�� �ִ� ���� �����Ѵ�. �ε��� x ������ ���Ұ� ������
	// out_of_range �ͼ����� ������.
	const T& getElementAt(size_t x) const;

	// �ε��� x ������ ���� �����Ѵ�. �ε��� x�� ���� �迭�� ũ�⸦ �����
	// ������ �� �Ҵ��Ѵ�.
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
	mElements = new T[mSize] {}; // ���Ҹ� 0���� �ʱ�ȭ�Ѵ�.
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
	// �� ū �迭�� �����Ѵ�. ���� 0���� �ʱ�ȭ�Ѵ�.
	auto newArray = std::make_unique<T[]>(newSize);

	// ���� ������ �迭�� �ݵ�� ����(mSize)���� Ŀ�� �Ѵ�.
	for (size_t i = 0; i < mSize; i++) {
		// ���� �迭�� ���Ҹ� ��� �� �迭�� �����Ѵ�.
		newArray[i] = mElements[i];
	}

	// ���� �迭�� �����ϰ� �� �迭�� �����Ѵ�.
	delete[] mElements;
	mSize = newSize;
	mElements = newArray.release();
}

template <typename T>
T& Array<T>::operator[](size_t x)
{
	if (x >= mSize) {
		// Ŭ���̾�Ʈ�� ��û�� ���� �ڷ� kAllocSize��ŭ ������ �Ҵ��Ѵ�.
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
		// Ŭ���̾�Ʈ�� ��û�� ���� �ڷ� kAllocSize��ŭ ������ �Ҵ��Ѵ�.
		resize(x + kAllocSize);
	}
	mElements[x] = val;
}

template <typename T>
size_t Array<T>::getSize() const
{
	return mSize;
}
