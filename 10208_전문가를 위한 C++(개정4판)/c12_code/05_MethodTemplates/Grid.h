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

	// ���� �����ڿ� ���� ���� �����ڸ� ��������� ����Ʈ�� �����Ѵ�.
	Grid(const Grid& src) = default;
	Grid<T>& operator=(const Grid& rhs) = default;

	// �̵� �����ڿ� �̵� ���� �����ڸ� ��������� ����Ʈ�� �����Ѵ�.
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
	// �� �������� ctor-�̴ϼȶ�������
	// ������ ���� �޸𸮸� �Ҵ��ϴ� �۾��� ���� �����ڿ� �����Ѵ�.

	// �׷��� ���� �����͸� �����Ѵ�.
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
	// �ڱ� �ڽ��� ������ ��쿡 ���� ���� ó���� �� �ʿ䰡 ����.
	// �� ������ ���� �����ڴ� T�� E�� ���� ������ ȣ����� �ʱ� �����̴�.

	// ���� �� �¹ٲٱ� ����
	Grid<T> temp(rhs); // ��� �۾��� �ӽ� �ν��Ͻ����� ó���Ѵ�.
	swap(temp);        // ���ܰ� �߻����� �ʴ� �������θ� ó���Ѵ�.
	return *this;
}
