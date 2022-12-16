#pragma once
#include <iostream>
#include <vector>

class Square;
class Board;

enum PieceColor {
	COLOR_WHITE,
	COLOR_BLACK
};

class Piece
{
public:
	const PieceColor Color;
	const char Symbol = 'x';

	Piece(PieceColor color) : Color(color)
	{
		std::cout << "Piece Created" << std::endl;
	}

	~Piece()
	{
		std::cout << "Piece Destroyed" << std::endl;
	}

	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const = 0; // Returns the legal squares to move the piece to
	Square* GetRandomLegalMove(Board* board, Square* square) const;
	virtual char GetSymbol() const { return Symbol; };
	friend std::ostream& operator<<(std::ostream& os, const Piece& piece);
};

class Rook : public Piece
{
public:
	const char Symbol = 'R';

	Rook(PieceColor color) : Piece(color) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'R' : 'r'; };
	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
};

class Bishop : public Piece
{
public:
	const char Symbol = 'B';

	Bishop(PieceColor color) : Piece(color) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'B' : 'b'; };
	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
};

class Queen : public Piece
{
public:
	const char Symbol = 'Q';

	Queen(PieceColor color) : Piece(color) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'Q' : 'q'; };
	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
};

class King : public Piece
{
public:
	const char Symbol = 'K';

	King(PieceColor color) : Piece(color) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'K' : 'k'; };
	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
};

class Knight : public Piece
{
public:
	const char Symbol = 'N';

	Knight(PieceColor color) : Piece(color) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'N' : 'n'; };
	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
};

class Pawn : public Piece
{
public:
	const char Symbol = 'P';

	Pawn(PieceColor color) : Piece(color) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'P' : 'p'; };
	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
};