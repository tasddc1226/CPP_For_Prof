#include "GameBoard.h"
#include <utility>

GameBoard::GameBoard(size_t width, size_t height)
	: mWidth(width), mHeight(height)
{
	mCells = new GamePiece*[mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new GamePiece[mHeight];
	}
}

GameBoard::GameBoard(const GameBoard& src)
	: GameBoard(src.mWidth, src.mHeight)
{
	// 이 생성자의 생성자 이니셜라이저는 먼저 비복제 생성자에
	// 메모리를 적절히 할당하는 작업을 위임한다.

	// 그러고 나서 데이터를 복제한다.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

GameBoard::~GameBoard()
{
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
	mWidth = mHeight = 0;
}

void swap(GameBoard& first, GameBoard& second) noexcept
{
	using std::swap;

	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells);
}

GameBoard& GameBoard::operator=(const GameBoard& rhs)
{
	// 자기 자신에 대입하는지 검사한다.
	if (this == &rhs) {
		return *this;
	}

	// 복제 후 맞바꾸기
	GameBoard temp(rhs); // 모든 작업을 임시 인스턴스에서 처리한다.
	swap(*this, temp);   // 익셉션을 던지지 않는 연산으로만 처리한다.
	return *this;
}

const GamePiece& GameBoard::at(size_t x, size_t y) const
{
	return mCells[x][y];
}

GamePiece& GameBoard::at(size_t x, size_t y)
{
	return const_cast<GamePiece&>(std::as_const(*this).at(x, y));
}