#pragma once
// Spreadsheet 클래스에 브릿지 패턴 적용
#include "SpreadsheetCell.h"
#include <memory>

// 전방 선언
class SpreadsheetApplication;
// public interface class로 정의
class Spreadsheet
{
	public:
		Spreadsheet(const SpreadsheetApplication& theApp,
			size_t width = kMaxWidth, size_t height = kMaxHeight);
		Spreadsheet(const Spreadsheet& src);
		~Spreadsheet();

		Spreadsheet& operator=(const Spreadsheet& rhs);
		
		void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
		SpreadsheetCell& getCellAt(size_t x, size_t y);
		
		size_t getId() const;

		static const size_t kMaxHeight = 100;
		static const size_t kMaxWidth = 100;

		friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;

	private:
		// 구현코드는 Impl이라는 이름의 private 중첩 클래스로 정의
		// => Spreadsheet class는 Impl 인스턴스에 대한 표인터 데이터 멤버 하나만 갖게 됨.
		class Impl; 
		std::unique_ptr<Impl> mImpl;
};
