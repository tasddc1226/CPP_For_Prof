#pragma once

#include "Grid.h"
#include <cstddef>
#include <stdexcept>
#include <optional>
#include <utility>
#include <string>

template <size_t WIDTH, size_t HEIGHT>
class Grid<const char*, WIDTH, HEIGHT>
{
public:
	Grid() = default;
	virtual ~Grid() = default;

	// 복제 생성자와 복제 대입 연산자를 명시적으로 디폴트로 지정한다.
	Grid(const Grid& src) = default;
	Grid& operator=(const Grid& rhs) = default;

	std::optional<std::string>& at(size_t x, size_t y);
	const std::optional<std::string>& at(size_t x, size_t y) const;

	size_t getHeight() const { return HEIGHT; }
	size_t getWidth() const { return WIDTH; }

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::optional<std::string> mCells[WIDTH][HEIGHT];
};

template <size_t WIDTH, size_t HEIGHT>
void Grid<const char*, WIDTH, HEIGHT>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= WIDTH || y >= HEIGHT) {
		throw std::out_of_range("");
	}
}

template <size_t WIDTH, size_t HEIGHT>
const std::optional<std::string>& Grid<const char*, WIDTH, HEIGHT>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

template <size_t WIDTH, size_t HEIGHT>
std::optional<std::string>& Grid<const char*, WIDTH, HEIGHT>::at(size_t x, size_t y)
{
	return const_cast<std::optional<std::string>&>(std::as_const(*this).at(x, y));
}
