#pragma once

#include <cstddef>
#include "Spreadsheet.h"
#include "SpreadsheetCell.h"

class Spreadsheet::Impl
{
public:
	Impl(const SpreadsheetApplication& theApp,
		size_t width, size_t height);
	Impl(const Impl& src);
	~Impl();
	Impl& operator=(const Impl& rhs);

	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	size_t getId() const;

private:
	void verifyCoordinate(size_t x, size_t y) const;
	// Impl class는 Spreadsheet의 중첩 클래스이므로 Impl 객체를 맞바꾸는 전역 friend swap() 함수를 private 메서드로 정의
	void swap(Impl& other) noexcept; 

	size_t mId = 0;
	size_t mWidth = 0;
	size_t mHeight = 0;
	SpreadsheetCell** mCells = nullptr;

	const SpreadsheetApplication& mTheApp;

	static size_t sCounter;
};
