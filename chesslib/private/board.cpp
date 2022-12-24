#include "../public/board.h"
#include <iostream>

Board::Board()
	: RowCount(8), ColCount(8), ColorTurn(0)
{
	// Default constructor creates a standard game
	// 8 x 8 board, two colors, 32 standard pieces
	std::cout << "New Standard Game" << std::endl;

	Pieces = std::vector<Piece*>(RowCount * ColCount, nullptr);

	// Whites
	// Question? How acceptable is that code? Is using template for this correct?
	AddPiece<Rook>(COLOR_WHITE, 0, 0);
	AddPiece<Rook>(COLOR_WHITE, 0, 7);

	AddPiece<Knight>(COLOR_WHITE, 0, 1);
	AddPiece<Knight>(COLOR_WHITE, 0, 6);

	AddPiece<Bishop>(COLOR_WHITE, 0, 2);
	AddPiece<Bishop>(COLOR_WHITE, 0, 5);

	AddPiece<Queen>(COLOR_WHITE, 0, 3);
	AddPiece<King>(COLOR_WHITE, 0, 4);

	for (int i = 0; i < ColCount; i++)
		AddPiece<Pawn>(COLOR_WHITE, 1, i);

	// Blacks
	AddPiece<Rook>(COLOR_BLACK, 7, 0);
	AddPiece<Rook>(COLOR_BLACK, 7, 7);

	AddPiece<Knight>(COLOR_BLACK, 7, 1);
	AddPiece<Knight>(COLOR_BLACK, 7, 6);

	AddPiece<Bishop>(COLOR_BLACK, 7, 2);
	AddPiece<Bishop>(COLOR_BLACK, 7, 5);

	AddPiece<Queen>(COLOR_BLACK, 7, 3);
	AddPiece<King>(COLOR_BLACK, 7, 4);

	for (int i = 0; i < ColCount; i++)
		AddPiece<Pawn>(COLOR_BLACK, 6, i);
}


Piece* Board::GetPiece(int row, int col) const
{
	return Pieces[row * ColCount + col];
}

Piece* Board::GetPiece(SquareCoordinate square) const
{
	return GetPiece(square.Row, square.Col);
}

Piece* Board::GetRandomPiece(PieceColor color) const
{
	std::vector<Piece*> colorPieces;
	for (Piece* piece : Pieces)
	{
		if (piece && piece->Color == color)
		{
			colorPieces.push_back(piece);
		}
	}
	
	if (!colorPieces.size())
		return nullptr;

	Piece* piece;
	while (true)
	{
		srand(time(0) + rand());
		int index = rand() % colorPieces.size();
		piece = colorPieces[index];
		if (piece->GetLegalMoves().size())
			return piece;
	}
	return nullptr;
}

Piece* Board::GetRandomPiece() const
{
	return GetRandomPiece(Colors[ColorTurn]);
}


template <class PieceClass> bool Board::AddPiece(PieceColor color, int row, int col)
{
	if (GetPiece(row, col))
		return false;

	PieceClass* piece = new PieceClass(this, color, row, col);

	Pieces[row * ColCount + col] = piece;

	// Register the color if not already present
	if (std::find(Colors.begin(), Colors.end(), color) == Colors.end())
		Colors.push_back(color);

	return true;
}


bool Board::MovePiece(Piece* piece, int row, int col)
{
	Piece* oldPiece = GetPiece(row, col);
	if (oldPiece)
		delete oldPiece;

	Pieces[piece->Square.Row * ColCount + piece->Square.Col] = nullptr;
	Pieces[row * ColCount + col] = piece;
	piece->Square = { row, col };

	// Set the turn to be to the next color
	ColorTurn = (ColorTurn + 1) % Colors.size();

	return true;
}

bool Board::MovePiece(Piece* piece, SquareCoordinate square)
{
	return MovePiece(piece, square.Row, square.Col);
}

void Board::Draw()
{
	char s;
	for (int row = RowCount - 1; row >= 0; row--)
	{
		for (int col = 0; col < ColCount; col++)
		{
			Piece* piece = GetPiece(row, col);
			if (piece)
				s = piece->GetSymbol();
			else
				s = '.';

			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
}
