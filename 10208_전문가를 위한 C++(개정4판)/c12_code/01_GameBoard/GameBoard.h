#pragma once

#include <cstddef>
#include <vector>
#include <memory>

class GamePiece
{
public:
	virtual std::unique_ptr<GamePiece> clone() const = 0;
};

class GameBoard
{
public:
	explicit GameBoard(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	GameBoard(const GameBoard& src);   // 복제 생성자
	virtual ~GameBoard() = default;    // 가상 디폴트 소멸자
	GameBoard& operator=(const GameBoard& rhs); // 대입 연산자
	
	// 이동 생성자와 대입 연산자를 명시적으로 디폴트로 지정한다.
	GameBoard(GameBoard&& src) = default;
	GameBoard& operator=(GameBoard&& src) = default;

	std::unique_ptr<GamePiece>& at(size_t x, size_t y);
	const std::unique_ptr<GamePiece>& at(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }

	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

	friend void swap(GameBoard& first, GameBoard& second) noexcept;

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<std::vector<std::unique_ptr<GamePiece>>> mCells;
	size_t mWidth, mHeight;
};
