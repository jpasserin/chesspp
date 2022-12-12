#include "board.h"
#include <iostream>

Board::Board()
	: RowCount(8), ColCount(8)
{
	std::cout << "New Board" << std::endl;

	Squares.reserve(RowCount * ColCount);
	for (int row = 0; row < RowCount; row++)
		for (int col = 0; col < ColCount; col++)
			Squares.emplace_back(row, col);
	
	Color whites = Color();
	Color blacks = Color();
	//Colors = Color[whites, blacks];

	//Rook *rook = new Rook();
	Piece* rook = whites.AddRook();
	Square* square = GetSquare(4, 4);
	square->SetPiece(rook);
}

Square* Board::GetSquare(int row, int col)
{
	return &Squares[row * ColCount + col];
}