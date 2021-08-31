#pragma once

#include <cstddef>

class GamePiece {};

class GameBoard
{
public:
	// ���׸� GameBoard. ����ڰ� ũ�⸦ �����Ѵ�.
	explicit GameBoard(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	GameBoard(const GameBoard& src); // ���� ������
	virtual ~GameBoard();
	GameBoard& operator=(const GameBoard& rhs); // ���� ������

	GamePiece& at(size_t x, size_t y);
	const GamePiece& at(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }

	static const size_t kDefaultWidth = 100;
	static const size_t kDefaultHeight = 100;

	friend void swap(GameBoard& first, GameBoard& second) noexcept;

private:
	// ���� ���� �������� �����ϴ� ��ü
	GamePiece** mCells = nullptr;
	size_t mWidth = 0, mHeight = 0;
};
