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
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
	: Spreadsheet(src.mWidth, src.mHeight)
{
	cout << "Copy constructor" << endl;

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

	// �ڽ��� �����ϴ��� Ȯ���Ѵ�.
	if (this == &rhs) {
		return *this;
	}

	// ���� �� �¹ٲٱ�(copy-and-swap) ���� ����
	Spreadsheet temp(rhs); // ��� �۾��� �ӽ� �ν��Ͻ����� ó���Ѵ�.
	swap(*this, temp); // ���ܸ� �߻����� �ʴ� �������θ� ó���Ѵ�.
	return *this;
}

// �̵� ������
Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept
	: Spreadsheet()
{
	cout << "Move constructor" << endl;

	swap(*this, src);
}

// �̵� ���� ������
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
{
	cout << "Move assignment operator" << endl;

	Spreadsheet temp(std::move(rhs));
	swap(*this, temp);
	return *this;
}
