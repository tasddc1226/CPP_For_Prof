#pragma once

#include <cstddef>
#include <string>
#include <string_view>

class SpreadsheetCell
{
public:
	SpreadsheetCell() = default;
	SpreadsheetCell(double initialValue);
	explicit SpreadsheetCell(std::string_view initialValue);

	void set(double inValue);
	void set(std::string_view inString);

	double getValue() const { mNumAccesses++; return mValue; }
	std::string getString() const { mNumAccesses++; return doubleToString(mValue); }

	static std::string doubleToString(double inValue);
	static double stringToDouble(std::string_view inString);

	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);
	SpreadsheetCell operator-() const;
	SpreadsheetCell& operator++();   // 선행 증가
	SpreadsheetCell operator++(int); // 후행 증가
	SpreadsheetCell& operator--();   // 선행 감소
	SpreadsheetCell operator--(int); // 후행 감소

	explicit operator double() const;
	operator std::string() const;

private:
	double mValue = 0;
	mutable size_t mNumAccesses = 0;
};

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
