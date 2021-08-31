#include "GameBoard.h"
#include <stdexcept>
#include <utility>
#include <new>

using namespace std;

GameBoard::GameBoard(size_t width, size_t height)
{
	mCells = new GamePiece*[width] {};	// Array is zero-initialized!

	// mWidth�� mHeight ����� ������ �̴ϼȶ������� �ʱ�ȭ�ϸ� �� �ȴ�.
	// �տ� ���� mCells�� ���������� �Ҵ����� ���� �ʱ�ȭ�ؾ� �ϱ� �����̴�.
	mWidth = width;
	mHeight = height;

	try {
		for (size_t i = 0; i < mWidth; i++) {
			mCells[i] = new GamePiece[mHeight];
		}
	} catch (...) {
		cleanup();
		// �߻��� �ͼ����� ��� bad_alloc �ͼ��� �ȿ� ��ø��Ų��.
		std::throw_with_nested(std::bad_alloc());
	}
}

GameBoard::GameBoard(const GameBoard& src)
	: GameBoard(src.mWidth, src.mHeight)
{
	// �� �����ڿ� ���� ������ �̴ϼȶ������� ���� ���� �����ڿ�
	// �޸𸮸� ������ �Ҵ��ϴ� �۾��� �����Ѵ�.

	// �׷��� ���� �����͸� �����Ѵ�.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

GameBoard::~GameBoard() noexcept
{
	cleanup();
}

void GameBoard::cleanup() noexcept
{
	for (size_t i = 0; i < mWidth; i++)
		delete[] mCells[i];
	delete[] mCells;
	mCells = nullptr;
	mWidth = mHeight = 0;
}

void GameBoard::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth)
		throw out_of_range("x-coordinate beyond width");
	if (y >= mHeight)
		throw out_of_range("y-coordinate beyond height");
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
	// �ڱ� �ڽſ� �����ϴ��� �˻��Ѵ�.
	if (this == &rhs) {
		return *this;
	}

	// ���� �� �¹ٲٱ�
	GameBoard temp(rhs); // ��� �۾��� �ӽ� �ν��Ͻ����� ó���Ѵ�.
	swap(*this, temp);   // �ͼ����� ������ �ʴ� �������θ� ó���Ѵ�.
	return *this;
}

const GamePiece& GameBoard::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

GamePiece& GameBoard::at(size_t x, size_t y)
{
	return const_cast<GamePiece&>(std::as_const(*this).at(x, y));
}
