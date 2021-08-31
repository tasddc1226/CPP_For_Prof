#pragma once

#include <cstddef>

class GamePiece {};

class GameBoard
{
public:
	// 제네릭 GameBoard. 사용자가 크기를 지정한다.
	explicit GameBoard(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	GameBoard(const GameBoard& src); // 복제 생성자
	virtual ~GameBoard();
	GameBoard& operator=(const GameBoard& rhs); // 대입 연산자

	GamePiece& at(size_t x, size_t y);
	const GamePiece& at(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }

	static const size_t kDefaultWidth = 100;
	static const size_t kDefaultHeight = 100;

	friend void swap(GameBoard& first, GameBoard& second) noexcept;

private:
	// 게임 말을 동적으로 저장하는 객체
	GamePiece** mCells = nullptr;
	size_t mWidth = 0, mHeight = 0;
};
