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
	
	Pieces.resize(2, std::vector<Piece*>(0));

	// Creates a new Rook for white and put it on a specific square

	AddPiece(new Rook(COLOR_WHITE), GetSquare(0, 0), COLOR_WHITE);
	AddPiece(new Rook(COLOR_WHITE), GetSquare(0, 7), COLOR_WHITE);

	AddPiece(new Knight(COLOR_WHITE), GetSquare(0, 1), COLOR_WHITE);
	AddPiece(new Knight(COLOR_WHITE), GetSquare(0, 6), COLOR_WHITE);

	AddPiece(new Bishop(COLOR_WHITE), GetSquare(0, 2), COLOR_WHITE);
	AddPiece(new Bishop(COLOR_WHITE), GetSquare(0, 5), COLOR_WHITE);

	AddPiece(new Queen(COLOR_WHITE), GetSquare(0, 3), COLOR_WHITE);
	AddPiece(new King(COLOR_WHITE), GetSquare(0, 4), COLOR_WHITE);

	for (int i = 0; i < ColCount; i++)
	{
		AddPiece(new Pawn(COLOR_WHITE), GetSquare(1, i), COLOR_WHITE);
	}
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

Piece* Board::GetRandomPiece(PieceColor color) const
{
	int index = rand() % Pieces[color].size();
	return Pieces[color][index];
}

bool Board::AddPiece(Piece* piece, Square* square, PieceColor color)
{
	if (PieceMap.find(square) != PieceMap.end())
		return false;

	Pieces[color].push_back(piece);
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