#include "../public/board.h"
#include <iostream>

Board::Board()
	: RowCount(8), ColCount(8), ColorTurn(0), GameStarted(false)
{
	// Default constructor creates a standard game
	// 8 x 8 board, two colors, 32 standard pieces
	std::cout << "New Standard Game" << std::endl;

	// Question? I'm using a vector. 
	// The size of the Array won't change but I don't know what is the size of it at compile time.
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

// Question? is it too much to use 'const int&' instead of just 'int'
// I'm guessing I can use that when it's a class, but it's not really needed for something like int, float or bool 
Piece* Board::GetPiece(const int& row, const int& col) const
{
	return Pieces[row * ColCount + col];
}

Piece* Board::GetRandomPiece(const PieceColor& color) const
{
	std::vector<Piece*> colorPieces;
	for (Piece* piece : Pieces)
		if (piece && piece->Color == color)
			colorPieces.push_back(piece);
	
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
	{
		Colors.push_back(color);
		TimeLeft.push_back(300000);
	}

	return true;
}

bool Board::MovePiece(Piece* piece, int row, int col)
{

	// Delete old piece
	const Piece* oldPiece = GetPiece(row, col);
	if (oldPiece)
		delete oldPiece;

	// Remove piece from old square
	Pieces[piece->Square.Row * ColCount + piece->Square.Col] = nullptr;
	// Move piece to the new square
	Pieces[row * ColCount + col] = piece;
	piece->Square = { row, col };

	// Update Time
	using namespace std::chrono;
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if (GameStarted)
	{
		milliseconds delta = currentTime - LastMoveTime;
		TimeLeft[ColorTurn] = TimeLeft[ColorTurn] - delta.count();
	}
	else
	{
		GameStarted = true;
	}

	LastMoveTime = currentTime;

	// Set the turn to be to the next color
	ColorTurn = (ColorTurn + 1) % Colors.size();

	return true;
}

unsigned int Board::GetTimeLeft(const PieceColor& color) const
{
	if (GameStarted && color == ColorTurn)
	{
		using namespace std::chrono;
		milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		milliseconds delta = currentTime - LastMoveTime;
		return TimeLeft[color] - delta.count();
	}

	return TimeLeft[color];
}

unsigned int Board::GetTimeLeft() const
{
	return GetTimeLeft(Colors[ColorTurn]);
}

bool Board::MovePiece(Piece* piece, const SquareCoordinate& square)
{
	return MovePiece(piece, square.Row, square.Col);
}


void Board::Draw() const
{
	char s;
	for (int row = RowCount - 1; row >= 0; row--)
	{
		for (int col = 0; col < ColCount; col++)
		{
			const Piece* piece = GetPiece(row, col);
			if (piece)
				s = piece->GetSymbol();
			else
				s = '.';

			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
}
