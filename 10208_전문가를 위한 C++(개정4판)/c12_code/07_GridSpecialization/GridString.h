#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <optional>
#include <utility>
#include <string>

// ���ø� Ư��ȭ�� ������ �� ���� ���ø��� �ݵ�� ������ �� �־�� �Ѵ�.
// ���� Ư��ȭ�� ���ø��� �Բ� ���� ���ø��� �׻� �� �� �ֵ��� include ���� �߰��Ѵ�.
#include "Grid.h"

template <>
class Grid<const char*>
{
public:
	explicit Grid(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	virtual ~Grid() = default;

	// ���� �����ڿ� ���� ���� �����ڸ� ��������� ����Ʈ�� �����Ѵ�.
	Grid(const Grid& src) = default;
	Grid<const char*>& operator=(const Grid& rhs) = default;

	// �̵� �����ڿ� �̵� ���� �����ڸ� ��������� ����Ʈ�� �����Ѵ�.
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
