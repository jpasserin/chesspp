#include "../public/piece.h"
#include "../public/board.h"
#include "../public/square.h"


Square* Piece::GetRandomLegalMove(Board* board, Square* square) const
{
	std::vector<Square*> squares = GetLegalMoves(board, square);

	int index = rand() % squares.size();
	return squares[index];
}

std::vector<Square*> Rook::GetLegalMoves(Board* board, Square* square) const
{
	std::vector<Square*> legalSquares;
	Square* returnSquare;

	for (int row = square->Row + 1; row < board->RowCount; row++)
	{
		returnSquare = board->GetSquare(row, square->Col);
		legalSquares.push_back(returnSquare);
	}

	for (int row = square->Row - 1; row >= 0; row--)
	{
		returnSquare = board->GetSquare(row, square->Col);
		legalSquares.push_back(returnSquare);
	}

	for (int col = square->Col + 1; col < board->ColCount; col++)
	{
		returnSquare = board->GetSquare(square->Row, col);
		legalSquares.push_back(returnSquare);
	}

	for (int col = square->Col - 1; col >= 0; col--)
	{
		returnSquare = board->GetSquare(square->Row, col);
		legalSquares.push_back(returnSquare);
	}

	return legalSquares;
}


std::ostream& operator<<(std::ostream& os, const Piece& piece)
{
	os << typeid(piece).name();
	return os;
}