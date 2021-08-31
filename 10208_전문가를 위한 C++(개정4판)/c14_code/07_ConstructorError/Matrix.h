#pragma once

#include <cstddef>
#include <iostream>
#include <new>
#include <exception>

template <typename T>
class Matrix
{
public:
	Matrix(size_t width, size_t height);
	virtual ~Matrix();

private:
	void cleanup();

	size_t mWidth = 0;
	size_t mHeight = 0;
	T** mMatrix = nullptr;
};

template <typename T>
Matrix<T>::Matrix(size_t width, size_t height)
{
	mMatrix = new T*[width] {};	// 배열을 영으로 초기화한다.

	// mWidth와 mHeight 멤버를 생성자 이니셜라이저로 초기화하면 안 된다.
	// 앞에 나온 mMatrix를 성공적으로 할당했을 때만 초기화해야 하기 때문이다.
	mWidth = width;
	mHeight = height;

	try {
		for (size_t i = 0; i < width; ++i) {
			mMatrix[i] = new T[height];
		}
	} catch (...) {
		std::cerr << "Exception caught in constructor, cleaning up..." << std::endl;
		cleanup();
		// 발생한 익셉션을 모두 bad_alloc 익셉션 안에 중첩시킨다.
		std::throw_with_nested(std::bad_alloc());
	}
}

template <typename T>
Matrix<T>::~Matrix()
{
	cleanup();
}

template <typename T>
void Matrix<T>::cleanup()
{
	for (size_t i = 0; i < mWidth; ++i)
		delete[] mMatrix[i];
	delete[] mMatrix;
	mMatrix = nullptr;
	mWidth = mHeight = 0;
}
