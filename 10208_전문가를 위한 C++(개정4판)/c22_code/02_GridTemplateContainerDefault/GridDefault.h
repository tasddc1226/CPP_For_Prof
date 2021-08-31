#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <utility>
#include <optional>

template <typename T, typename Container = std::vector<std::optional<T>>>
class Grid
{
public:
	explicit Grid(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	virtual ~Grid() = default;

	// 복제 생성자와 복제 대입 연산자를 명시적으로 디폴트로 지정한다.
	Grid(const Grid& src) = default;
	Grid<T, Container>& operator=(const Grid& rhs) = default;

	// 이동 생성자와 이동 대입 연산자를 명시적으로 디폴트로 지정한다.
	Grid(Grid&& src) = default;
	Grid<T, Container>& operator=(Grid&& rhs) = default;

	typename Container::value_type& at(size_t x, size_t y);
	const typename Container::value_type& at(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }

	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<Container> mCells;
	size_t mWidth = 0, mHeight = 0;
};

template <typename T, typename Container>
Grid<T, Container>::Grid(size_t width, size_t height)
	: mWidth(width)
	, mHeight(height)
{
	mCells.resize(mWidth);
	for (auto& column : mCells) {
		column.resize(mHeight);
	}
}

template <typename T, typename Container>
void Grid<T, Container>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

template <typename T, typename Container>
const typename Container::value_type& Grid<T, Container>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

template <typename T, typename Container>
typename Container::value_type& Grid<T, Container>::at(size_t x, size_t y)
{
	return const_cast<typename Container::value_type&>(
		std::as_const(*this).at(x, y));
}
