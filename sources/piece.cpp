#include "piece.h"
#include "board.h"
#include "square.h"


std::vector<Square*> Rook::GetLegalMove(Board* board, Square* square) 
{
	std::vector<Square*> legalSquares;
	Square* returnSquare;

	for (int row = square->Row + 1; row < board->RowCount; row++)
	{
		returnSquare = board->GetSquare(row, square->Col);
		legalSquares.push_back(returnSquare);
	}

	for (int row = square->Row - 1; row > 0; row--)
	{
		returnSquare = board->GetSquare(row, square->Col);
		legalSquares.push_back(returnSquare);
	}

	for (int col = square->Col + 1; col < board->ColCount; col++)
	{
		returnSquare = board->GetSquare(square->Row, col);
		legalSquares.push_back(returnSquare);
	}

	for (int col = square->Col - 1; col > 0; col--)
	{
		returnSquare = board->GetSquare(square->Row, col);
		legalSquares.push_back(returnSquare);
	}

	return legalSquares;
}

std::ostream& operator<<(std::ostream& os, const Piece& piece)
{
	os << "My Piece Name" << typeid(piece).name();
	return os;
}