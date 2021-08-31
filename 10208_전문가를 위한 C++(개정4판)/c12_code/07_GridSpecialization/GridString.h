#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <optional>
#include <utility>
#include <string>

// 템플릿 특수화를 적용할 때 원본 템플릿도 반드시 참조할 수 있어야 한다.
// 따라서 특수화한 템플릿과 함께 원본 템플릿도 항상 볼 수 있도록 include 문을 추가한다.
#include "Grid.h"

template <>
class Grid<const char*>
{
public:
	explicit Grid(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	virtual ~Grid() = default;

	// 복제 생성자와 복제 대입 연산자를 명시적으로 디폴트로 선언한다.
	Grid(const Grid& src) = default;
	Grid<const char*>& operator=(const Grid& rhs) = default;

	// 이동 생성자와 이동 대입 연산자를 명시적으로 디폴트로 선언한다.
	Grid(Grid&& src) = default;
	Grid<const char*>& operator=(Grid&& rhs) = default;

	std::optional<std::string>& at(size_t x, size_t y);
	const std::optional<std::string>& at(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }

	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<std::vector<std::optional<std::string>>> mCells;
	size_t mWidth, mHeight;
};

Grid<const char*>::Grid(size_t width, size_t height)
	: mWidth(width)
	, mHeight(height)
{
	mCells.resize(mWidth);
	for (auto& column : mCells) {
		column.resize(mHeight);
	}
}

void Grid<const char*>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

const std::optional<std::string>& Grid<const char*>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

std::optional<std::string>& Grid<const char*>::at(size_t x, size_t y)
{
	return const_cast<std::optional<std::string>&>(std::as_const(*this).at(x, y));
}
