#include "Spreadsheet.h"
#include <stdexcept>
#include <utility>

Spreadsheet::Spreadsheet(size_t width, size_t height)
	: mWidth(width)
	, mHeight(height)
{
	mCells = new SpreadsheetCell*[mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}

Spreadsheet::~Spreadsheet()
{
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
	: Spreadsheet(src.mWidth, src.mHeight)
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

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
	verifyCoordinate(x, y);
	mCells[x][y] = cell;
}

const SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	return const_cast<SpreadsheetCell&>(std::as_const(*this).getCellAt(x, y));
	//return const_cast<SpreadsheetCell&>(static_cast<const Spreadsheet&>(*this).getCellAt(x, y)); // C++17 이전 문법
}

void swap(Spreadsheet& first, Spreadsheet& second) noexcept
{
	using std::swap;

	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells);
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	// 자기 자신 대입 여부 확인
	if (this == &rhs) {
		return *this;
	}

	// 복제 후 스왑 구문
	Spreadsheet temp(rhs); // 모든 작업을 임시 인스턴스에서 처리한다.
	swap(*this, temp); // 익셉션을 던지지 않는 연산으로 결과를 반영한다.
	return *this;
}
