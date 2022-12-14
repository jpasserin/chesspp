#include "board.h"
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
	std::shared_ptr<Piece> rook = Materials[0]->AddRook();
	//Piece* rook = whites.AddRook().get();
	Square* square = GetSquare(4, 4);
	square->SetPiece(rook);
}

Square* Board::GetSquare(int row, int col) 
{
	return &Squares[row * ColCount + col];
}

void Board::Draw() 
{
	for (int row = RowCount - 1; row >= 0; row--)
	{
		for (int col = 0; col < ColCount; col++)
		{
			const char* s = GetSquare(row, col)->GetSymbol();
			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
}