#pragma once

#include "Grid.h"
#include <memory>

template <typename T>
class Grid<T*>
{
public:
	explicit Grid(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	virtual ~Grid() = default;

	// 복제 생성자와 복제 대입 연산자
	Grid(const Grid& src);
	Grid<T*>& operator=(const Grid& rhs);

	// 이동 생성자와 이동 대입 연산자를 명시적으로 디폴트로 지정한다.
	Grid(Grid&& src) = default;
	Grid<T*>& operator=(Grid&& rhs) = default;

	void swap(Grid& other) noexcept;

	std::unique_ptr<T>& at(size_t x, size_t y);
	const std::unique_ptr<T>& at(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }

	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<std::vector<std::unique_ptr<T>>> mCells;
	size_t mWidth = 0, mHeight = 0;
};

template <typename T>
Grid<T*>::Grid(size_t width, size_t height)
	: mWidth(width)
	, mHeight(height)
{
	mCells.resize(mWidth);
	for (auto& column : mCells) {
		column.resize(mHeight);
	}
}

template <typename T>
void Grid<T*>::swap(Grid& other) noexcept
{
	using std::swap;

	swap(mWidth, other.mWidth);
	swap(mHeight, other.mHeight);
	swap(mCells, other.mCells);
}

template <typename T>
Grid<T*>::Grid(const Grid& src)
	: Grid(src.mWidth, src.mHeight)
{
	// The ctor-initializer of this constructor delegates first to the
	// non-copy constructor to allocate the proper amount of memory.

	// The next step is to copy the data.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			// Make a deep copy of the element by using its copy constructor.
			if (src.mCells[i][j]) {
				mCells[i][j].reset(new T(*(src.mCells[i][j])));
			}
		}
	}
}

template <typename T>
Grid<T*>& Grid<T*>::operator=(const Grid& rhs)
{
	// Check for self-assignment.
	if (this == &rhs) {
		return *this;
	}

	// Use copy-and-swap idiom.
	auto copy = rhs;    // Do all the work in a temporary instance
	swap( copy);        // Commit the work with only non-throwing operations
	return *this;
}

template <typename T>
void Grid<T*>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

template <typename T>
const std::unique_ptr<T>& Grid<T*>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

template <typename T>
std::unique_ptr<T>& Grid<T*>::at(size_t x, size_t y)
{
	return const_cast<std::unique_ptr<T>&>(std::as_const(*this).at(x, y));
}
