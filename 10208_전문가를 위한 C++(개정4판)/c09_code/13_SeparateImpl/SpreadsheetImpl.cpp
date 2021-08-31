#include "SpreadsheetImpl.h"
#include "Spreadsheet.h"
#include <stdexcept>
#include <utility>
#include <algorithm>

size_t Spreadsheet::Impl::sCounter;

Spreadsheet::Impl::Impl(const SpreadsheetApplication& theApp,
	size_t width, size_t height)
	: mId(sCounter++)
	, mWidth(std::min(width, Spreadsheet::kMaxWidth))
	, mHeight(std::min(height, Spreadsheet::kMaxHeight))
	, mTheApp(theApp)
{
	mCells = new SpreadsheetCell*[mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}

Spreadsheet::Impl::~Impl()
{
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
}

Spreadsheet::Impl::Impl(const Impl& src)
	: Impl(src.mTheApp, src.mWidth, src.mHeight)
{
	// �� �������� ctor-�̴ϼȶ������� ���� ������ ���� �޸𸮸� �Ҵ��ϴ� �۾���
	// ���� ������ �����ڿ��� �����Ѵ�.

	// �׷��� ���� ������ ���� �����ϴ� �۾��� �����Ѵ�.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

void Spreadsheet::Impl::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

void Spreadsheet::Impl::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
	verifyCoordinate(x, y);
	mCells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::Impl::getCellAt(size_t x, size_t y)
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

void Spreadsheet::Impl::swap(Impl& other) noexcept
{
	using std::swap;

	swap(mWidth, other.mWidth);
	swap(mHeight, other.mHeight);
	swap(mCells, other.mCells);
}

Spreadsheet::Impl& Spreadsheet::Impl::operator=(const Impl& rhs)
{
	// �ڽ��� �����ϴ��� Ȯ���Ѵ�.
	if (this == &rhs) {
		return *this;
	}

	// ���� �� �¹ٲٱ�(copy-and-swap) ���� ����
	Impl temp(rhs); // ��� �۾��� �ӽ� �ν��Ͻ����� ó���Ѵ�.
	swap(temp); // ���ܸ� �߻����� �ʴ� �������θ� ó���Ѵ�.
	return *this;
}

size_t Spreadsheet::Impl::getId() const
{
	return mId;
}
