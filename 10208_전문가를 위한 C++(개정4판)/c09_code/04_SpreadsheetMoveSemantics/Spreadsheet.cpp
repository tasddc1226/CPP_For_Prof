#include "Spreadsheet.h"
#include <stdexcept>
#include <utility>
#include <iostream>

using namespace std;

Spreadsheet::Spreadsheet(size_t width, size_t height)
	: mWidth(width)
	, mHeight(height)
{
	cout << "Normal constructor" << endl;

	mCells = new SpreadsheetCell*[mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}

Spreadsheet::~Spreadsheet()
{
	cleanup();
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
	: Spreadsheet(src.mWidth, src.mHeight)
{
	cout << "Copy constructor" << endl;

	// 이 생성자의 ctor-이니셜라이저는 먼저 적절한 양의 메모리를 할당하는 작업을
	// 비복제 버전의 생성자에게 위임한다.

	// 그러고 나서 실제로 값을 복제하는 작업을 수행한다.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

void Spreadsheet::cleanup() noexcept
{
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
	mWidth = mHeight = 0;
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

SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	verifyCoordinate(x, y);
	return mCells[x][y];
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
	cout << "Copy assignment operator" << endl;

	// 자신을 대입하는지 확인한다.
	if (this == &rhs) {
		return *this;
	}

	// 복제 후 맞바꾸기(copy-and-swap) 패턴 적용
	Spreadsheet temp(rhs); // 모든 작업을 임시 인스턴스에서 처리한다.
	swap(*this, temp); // 예외를 발생하지 않는 연산으로만 처리한다.
	return *this;
}

void Spreadsheet::moveFrom(Spreadsheet& src) noexcept
{
	// 얕은 복제 적용
	mWidth = src.mWidth;
	mHeight = src.mHeight;
	mCells = src.mCells;

	// 원본 객체를 리셋한다. 소유권이 이동했기 때문이다.
	src.mWidth = 0;
	src.mHeight = 0;
	src.mCells = nullptr;
}

// 이동 생성자
Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept
{
	cout << "Move constructor" << endl;

	moveFrom(src);
}

// 이동 대입 연산자
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
{
	cout << "Move assignment operator" << endl;

	// 자기 자신 대입 여부 검사
	if (this == &rhs) {
		return *this;
	}

	// 기존 메모리 해제
	cleanup();

	moveFrom(rhs);

	return *this;
}
