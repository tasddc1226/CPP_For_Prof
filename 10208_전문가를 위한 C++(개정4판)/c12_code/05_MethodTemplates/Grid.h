#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <optional>
#include <utility>

template <typename T>
class Grid
{
public:
	explicit Grid(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	virtual ~Grid() = default;

	// 복제 생성자와 복제 대입 연산자를 명시적으로 디폴트로 지정한다.
	Grid(const Grid& src) = default;
	Grid<T>& operator=(const Grid& rhs) = default;

	// 이동 생성자와 이동 대입 연산자를 명시적으로 디폴트로 지정한다.
	Grid(Grid&& src) = default;
	Grid<T>& operator=(Grid&& rhs) = default;

	template <typename E>
	Grid(const Grid<E>& src);

	template <typename E>
	Grid<T>& operator=(const Grid<E>& rhs);

	void swap(Grid& other) noexcept;

	std::optional<T>& at(size_t x, size_t y);
	const std::optional<T>& at(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }

	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<std::vector<std::optional<T>>> mCells;
	size_t mWidth, mHeight;
};

template <typename T>
Grid<T>::Grid(size_t width, size_t height)
	: mWidth(width)
	, mHeight(height)
{
	mCells.resize(mWidth);
	for (auto& column : mCells) {
		column.resize(mHeight);
	}
}

template <typename T>
void Grid<T>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

template <typename T>
const std::optional<T>& Grid<T>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

template <typename T>
std::optional<T>& Grid<T>::at(size_t x, size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}

template <typename T>
template <typename E>
Grid<T>::Grid(const Grid<E>& src)
	: Grid(src.getWidth(), src.getHeight())
{
	// 이 생성자의 ctor-이니셜라이저는
	// 적절한 양의 메모리를 할당하는 작업을 비복제 생성자에 위임한다.

	// 그러고 나서 데이터를 복제한다.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.at(i, j);
		}
	}
}

template <typename T>
void Grid<T>::swap(Grid<T>& other) noexcept
{
	using std::swap;

	swap(mWidth, other.mWidth);
	swap(mHeight, other.mHeight);
	swap(mCells, other.mCells);
}

template <typename T>
template <typename E>
Grid<T>& Grid<T>::operator=(const Grid<E>& rhs)
{
	// 자기 자신을 대입할 경우에 대한 예외 처리를 할 필요가 없다.
	// 이 버전의 대입 연산자는 T와 E가 서로 같으면 호출되지 않기 때문이다.

	// 복제 후 맞바꾸기 구문
	Grid<T> temp(rhs); // 모든 작업을 임시 인스턴스에서 처리한다.
	swap(temp);        // 예외가 발생하지 않는 연산으로만 처리한다.
	return *this;
}
