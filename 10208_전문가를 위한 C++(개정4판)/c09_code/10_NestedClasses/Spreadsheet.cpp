#include "Spreadsheet.h"
#include <stdexcept>
#include <utility>
#include <algorithm>

using namespace std;

size_t Spreadsheet::sCounter;

Spreadsheet::Spreadsheet(size_t width, size_t height,
	const SpreadsheetApplication& theApp)
	: mId(sCounter++)
	, mWidth(std::min(width, kMaxWidth))
	, mHeight(std::min(height, kMaxHeight))
	, mTheApp(theApp)
{
	mCells = new Cell*[mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new Cell[mHeight];
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
	: Spreadsheet(src.mWidth, src.mHeight, src.mTheApp)
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

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

void Spreadsheet::setCellAt(size_t x, size_t y, const Cell& cell)
{
	verifyCoordinate(x, y);
	mCells[x][y] = cell;
}

Spreadsheet::Cell& Spreadsheet::getCellAt(size_t x, size_t y)
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
	// �ڽ��� �����ϴ��� Ȯ���Ѵ�.
	if (this == &rhs) {
		return *this;
	}

	// ���� �� �¹ٲٱ�(copy-and-swap) ���� ����
	Spreadsheet temp(rhs); // ��� �۾��� �ӽ� �ν��Ͻ����� ó���Ѵ�.
	swap(*this, temp); // ���ܸ� �߻����� �ʴ� �������θ� ó���Ѵ�.
	return *this;
}

size_t Spreadsheet::getId() const
{
	return mId;
}





Spreadsheet::Cell::Cell(double initialValue)
	: mValue(initialValue)
{
}

Spreadsheet::Cell::Cell(string_view initialValue)
	: mValue(stringToDouble(initialValue))
{
}

void Spreadsheet::Cell::set(double inValue)
{
	mValue = inValue;
}

void Spreadsheet::Cell::set(string_view inString)
{
	mValue = stringToDouble(inString);
}

string Spreadsheet::Cell::doubleToString(double inValue)
{
	return to_string(inValue);
}

double Spreadsheet::Cell::stringToDouble(string_view inString)
{
	return strtod(inString.data(), nullptr);
}
