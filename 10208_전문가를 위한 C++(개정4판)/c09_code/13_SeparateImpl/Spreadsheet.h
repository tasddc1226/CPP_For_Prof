#pragma once
// Spreadsheet Ŭ������ �긴�� ���� ����
#include "SpreadsheetCell.h"
#include <memory>

// ���� ����
class SpreadsheetApplication;
// public interface class�� ����
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
		// �����ڵ�� Impl�̶�� �̸��� private ��ø Ŭ������ ����
		// => Spreadsheet class�� Impl �ν��Ͻ��� ���� ǥ���� ������ ��� �ϳ��� ���� ��.
		class Impl; 
		std::unique_ptr<Impl> mImpl;
};
