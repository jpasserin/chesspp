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
			Squares.push_back(new Square(row, col));
	
	Pieces.resize(2, std::vector<Piece*>(0));

	// Whites
	AddPiece(new Rook(COLOR_WHITE), GetSquare(0, 0), COLOR_WHITE);
	AddPiece(new Rook(COLOR_WHITE), GetSquare(0, 7), COLOR_WHITE);

	AddPiece(new Knight(COLOR_WHITE), GetSquare(0, 1), COLOR_WHITE);
	AddPiece(new Knight(COLOR_WHITE), GetSquare(0, 6), COLOR_WHITE);

	AddPiece(new Bishop(COLOR_WHITE), GetSquare(0, 2), COLOR_WHITE);
	AddPiece(new Bishop(COLOR_WHITE), GetSquare(0, 5), COLOR_WHITE);

	AddPiece(new Queen(COLOR_WHITE), GetSquare(0, 3), COLOR_WHITE);
	AddPiece(new King(COLOR_WHITE), GetSquare(0, 4), COLOR_WHITE);

	for (int i = 0; i < ColCount; i++)
		AddPiece(new Pawn(COLOR_WHITE), GetSquare(1, i), COLOR_WHITE);


	// Blacks
	AddPiece(new Rook(COLOR_BLACK), GetSquare(7, 0), COLOR_BLACK);
	AddPiece(new Rook(COLOR_BLACK), GetSquare(7, 7), COLOR_BLACK);

	AddPiece(new Knight(COLOR_BLACK), GetSquare(7, 1), COLOR_BLACK);
	AddPiece(new Knight(COLOR_BLACK), GetSquare(7, 6), COLOR_BLACK);

	AddPiece(new Bishop(COLOR_BLACK), GetSquare(7, 2), COLOR_BLACK);
	AddPiece(new Bishop(COLOR_BLACK), GetSquare(7, 5), COLOR_BLACK);

	AddPiece(new Queen(COLOR_BLACK), GetSquare(7, 3), COLOR_BLACK);
	AddPiece(new King(COLOR_BLACK), GetSquare(7, 4), COLOR_BLACK);

	for (int i = 0; i < ColCount; i++)
		AddPiece(new Pawn(COLOR_BLACK), GetSquare(6, i), COLOR_BLACK);
}

Square* Board::GetSquare(int row, int col) const
{
	return Squares[row * ColCount + col];
}

Square* Board::GetSquare(Piece* piece) const
{
	for (auto m : PieceMap)
		if (piece == m.second)
			return m.first;

	return nullptr;
}

Piece* Board::GetPiece(Square* square) 
{
	if (PieceMap.find(square) == PieceMap.end())
		return nullptr;

	return PieceMap[square];
}

Piece* Board::GetRandomPiece(PieceColor color)
{
	Piece* piece;
	while (true)
	{
		srand(time(0) + rand());
		int index = rand() % Pieces[color].size();
		piece = Pieces[color][index];
		if (piece->GetLegalMoves(this, GetSquare(piece)).size())
			return piece;
	}
	return nullptr;
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
	Pieces;
	PieceMap;

	Square* oldSquare = GetSquare(piece);
	PieceMap.erase(oldSquare);
	Piece* oldPiece = PieceMap[square];
	if (oldPiece)
	{
		delete PieceMap[square];
		for (std::vector<Piece*>& Color : Pieces) 
			Color.erase(std::remove(Color.begin(), Color.end(), oldPiece), Color.end());
	}

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
			Square* square = GetSquare(row, col);
			Piece* piece = GetPiece(square);
			if (piece)
				s = piece->GetSymbol();
			else
				s = '.';

			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
}
