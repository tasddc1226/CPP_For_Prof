#include "GameBoard.h"

class ChessPiece : public GamePiece
{
public:
	virtual std::unique_ptr<GamePiece> clone() const override;
};

std::unique_ptr<GamePiece> ChessPiece::clone() const
{
	// 복제 생성자를 호출해서 이 인스턴스를 복제한다.
	return std::make_unique<ChessPiece>(*this);
}

void processGameBoard(const GameBoard& board)
{
	const std::unique_ptr<GamePiece>& pawn = board.at(0, 0);

	// 다음 문장은 컴파일 에러가 발생한다.
	//board.at(1, 2) = std::make_unique<ChessPiece>();
}

int main()
{
	GameBoard chessBoard(8, 8);
	auto pawn = std::make_unique<ChessPiece>();
	chessBoard.at(0, 0) = std::move(pawn);
	chessBoard.at(0, 1) = std::make_unique<ChessPiece>();
	chessBoard.at(0, 1) = nullptr;

	GameBoard board2;
	board2 = chessBoard;

	processGameBoard(board2);

	return 0;
}
