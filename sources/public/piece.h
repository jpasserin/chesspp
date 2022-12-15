#pragma once
#include <iostream>
#include <vector>

class Square;
class Board;
class Material;

enum PieceColor {
	COLOR_WHITE,
	COLOR_BLACK
};

class Piece
/* Abstract Piece class
*/
{

public:
	PieceColor Color;
	char Symbol = 'x';

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
	char Symbol = 'R';

	Rook(PieceColor color) : Piece(color) {}
	char GetSymbol() const override { return Symbol; };
	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
};

class Bishop : public Piece
{
public:
	char Symbol = 'B';

	Bishop(PieceColor color) : Piece(color) {}
	char GetSymbol() const override { return Symbol; };
	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
};

class Queen : public Piece
{
public:
	char Symbol = 'Q';

	Queen(PieceColor color) : Piece(color) {}
	char GetSymbol() const override { return Symbol; };
	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
};

class King : public Piece
{
public:
	char Symbol = 'K';

	King(PieceColor color) : Piece(color) {}
	char GetSymbol() const override { return Symbol; };
	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
};

class Knight : public Piece
{
public:
	char Symbol = 'N';

	Knight(PieceColor color) : Piece(color) {}
	char GetSymbol() const override { return Symbol; };
	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
}; 

class Pawn : public Piece
{
public:
	char Symbol = 'P';

	Pawn(PieceColor color) : Piece(color) {}
	char GetSymbol() const override { return Symbol; };
	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
};