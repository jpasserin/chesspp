#include "../public/board.h"
#include <iostream>

Board::Board()
	: RowCount(8), ColCount(8)
{
	// Default constructor creates a standard game
	// 8 x 8 board, two colors, 32 standard pieces
	std::cout << "New Standard Game" << std::endl;

	Squares.reserve(RowCount * ColCount);
	for (int row = 0; row < RowCount; row++)
		for (int col = 0; col < ColCount; col++)
			Squares.emplace_back(row, col);
	
	Materials[0] = new Material("White");
	Materials[1] = new Material("Black");

	// Creates a new Rook for white and put it on a specific square
	Piece* rook = Materials[0]->AddRook();
	AddPiece(rook, GetSquare(2, 1));
}


Material* Board::GetMaterial(int index) const
{
	return Materials[index];
}

Square* Board::GetSquare(int row, int col) 
{
	return &Squares[row * ColCount + col];
}

Square* Board::GetSquare(Piece* piece)
{
	for (auto m : PieceMap)
	{
		if (piece == m.second)
			return m.first;
	}

	return nullptr;
}

Piece* Board::GetPiece(Square* square)
{
	if (PieceMap.find(square) == PieceMap.end())
		return nullptr;

	return PieceMap[square];
}

bool Board::AddPiece(Piece* piece, Square* square)
{
	if (PieceMap.find(square) != PieceMap.end())
		return false;

	PieceMap[square] = piece;
}

bool Board::MovePiece(Piece* piece, Square* square)
{
	Square* oldSquare = GetSquare(piece);
	PieceMap.erase(oldSquare);
	PieceMap[square] = piece;
	return true;
}

void Board::Draw() 
{
	char s;
	for (int row = RowCount - 1; row >= 0; row--)
	{
		for (int col = 0; col < ColCount; col++)
		{
			Piece* piece = GetPiece(GetSquare(row, col));
			if (piece)
				s = piece->GetSymbol();
			else
				s = '.';

			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
}