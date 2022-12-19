#pragma once
#include <iostream>
#include <vector>
#include <string>

class Board;
class Duck;


enum PieceColor {
	COLOR_WHITE,
	COLOR_BLACK
};


struct SquareCoordinate
{
	int Row;
	int Col;
	bool Valid;

	SquareCoordinate() : Row(-1), Col(-1), Valid(false) {}
	SquareCoordinate(int row, int col) : Row(row), Col(col), Valid(true) {}

	std::string GetName() const
	{
		const char* ALPHABET = "abcdefghijklmnopqrstuvwxyz";
		return std::string(1, ALPHABET[Col]) + std::to_string(Row + 1);
	}
};

class Piece
{
public:
	const Board* mBoard;
	const PieceColor Color;
	SquareCoordinate Square;
	const char Symbol = 'x';

	Piece(Board* board, PieceColor color, int row, int col) : mBoard(board), Color(color), Square(SquareCoordinate(row, col))
	{
		std::cout << "Piece Created" << std::endl;
	}

	~Piece()
	{
		std::cout << "Piece Destroyed" << std::endl;
	}

protected:
	std::vector<SquareCoordinate> GetDirectionMoves(std::vector<std::pair<int, int>> directions, bool recursive) const;

public:
	std::vector<SquareCoordinate> virtual GetLegalMoves() const = 0; // Returns the legal squares to move the piece to
	SquareCoordinate GetRandomLegalMove() const;
	virtual char GetSymbol() const { return Symbol; }
	virtual const char* GetName() const { return "Piece"; }
	friend std::ostream& operator<<(std::ostream& os, const Piece& piece);
};


class Rook : public Piece
{
public:
	const char Symbol = 'R';

	Rook(Board* board, PieceColor color, int row, int col) : Piece(board, color, row, col) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'R' : 'r'; };
	virtual const char* GetName() const { return "Rook"; }
	std::vector<SquareCoordinate> virtual GetLegalMoves() const;
};

class Bishop : public Piece
{
public:
	const char Symbol = 'B';

	Bishop(Board* board, PieceColor color, int row, int col) : Piece(board, color, row, col) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'B' : 'b'; };
	virtual const char* GetName() const { return "Bishop"; }
	std::vector<SquareCoordinate> virtual GetLegalMoves() const;
};

class Queen : public Piece
{
public:
	const char Symbol = 'Q';

	Queen(Board* board, PieceColor color, int row, int col) : Piece(board, color, row, col) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'Q' : 'q'; };
	virtual const char* GetName() const { return "Queen"; }
	std::vector<SquareCoordinate> virtual GetLegalMoves() const;
};

class King : public Piece
{
public:
	const char Symbol = 'K';

	King(Board* board, PieceColor color, int row, int col) : Piece(board, color, row, col) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'K' : 'k'; };
	virtual const char* GetName() const { return "King"; }
	std::vector<SquareCoordinate> virtual GetLegalMoves() const;
};

class Knight : public Piece
{
public:
	const char Symbol = 'N';

	Knight(Board* board, PieceColor color, int row, int col) : Piece(board, color, row, col) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'N' : 'n'; };
	virtual const char* GetName() const { return "Knight"; }
	std::vector<SquareCoordinate> virtual GetLegalMoves() const;
};

class Pawn : public Piece
{
public:
	const char Symbol = 'P';

	Pawn(Board* board, PieceColor color, int row, int col) : Piece(board, color, row, col) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'P' : 'p'; };
	virtual const char* GetName() const { return "Pawn"; }
	std::vector<SquareCoordinate> virtual GetLegalMoves() const;
};