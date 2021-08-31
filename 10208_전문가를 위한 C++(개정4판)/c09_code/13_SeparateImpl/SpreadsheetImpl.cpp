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
	// 이 생성자의 ctor-이니셜라이저는 먼저 적절한 양의 메모리를 할당하는 작업을
	// 비복제 버전의 생성자에게 위임한다.

	// 그러고 나서 실제로 값을 복제하는 작업을 수행한다.
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
	// 자신을 대입하는지 확인한다.
	if (this == &rhs) {
		return *this;
	}

	// 복제 후 맞바꾸기(copy-and-swap) 패턴 적용
	Impl temp(rhs); // 모든 작업을 임시 인스턴스에서 처리한다.
	swap(temp); // 예외를 발생하지 않는 연산으로만 처리한다.
	return *this;
}

size_t Spreadsheet::Impl::getId() const
{
	return mId;
}
