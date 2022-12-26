#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <optional>

class Board;


enum PieceColor {
	COLOR_WHITE,
	COLOR_BLACK,
	COLOR_PURPLE,
	COLOR_GREEN
};


struct SquareCoordinate
{
	unsigned char Row;
	unsigned char Col;

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
	const int value = 0;

	Piece(Board* board, PieceColor color, unsigned char row, unsigned char col) : mBoard(board), Color(color), Square({ row, col })
	{
		std::cout << "Piece Created" << std::endl;
	}

	~Piece()
	{
		std::cout << "Piece Destroyed" << std::endl;
	}

	Piece(const Piece&) = delete; // Prevent copies of the class

	std::vector<SquareCoordinate> virtual GetLegalMoves() const = 0; // Returns the legal squares to move the piece to
	std::optional<SquareCoordinate> GetRandomLegalMove() const;
	virtual char GetSymbol() const { return Symbol; }
	virtual const char* GetName() const { return "Piece"; }
	friend std::ostream& operator<<(std::ostream& os, const Piece& piece);

protected:
	std::vector<SquareCoordinate> GetDirectionMoves(const std::vector<std::pair<char, char>> directions, bool recursive) const;

};


class Rook : public Piece
{
public:
	const char Symbol = 'R';
	const int value = 5;

	Rook(Board* board, PieceColor color, unsigned char row, unsigned char col) : Piece(board, color, row, col) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'R' : 'r'; };
	virtual const char* GetName() const { return "Rook"; }
	std::vector<SquareCoordinate> virtual GetLegalMoves() const;
};

class Bishop : public Piece
{
public:
	const char Symbol = 'B';
	const int value = 3;

	Bishop(Board* board, PieceColor color, unsigned char row, unsigned char col) : Piece(board, color, row, col) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'B' : 'b'; };
	virtual const char* GetName() const { return "Bishop"; }
	std::vector<SquareCoordinate> virtual GetLegalMoves() const;
};

class Queen : public Piece
{
public:
	const char Symbol = 'Q';
	const int value = 9;

	Queen(Board* board, PieceColor color, unsigned char row, unsigned char col) : Piece(board, color, row, col) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'Q' : 'q'; };
	virtual const char* GetName() const { return "Queen"; }
	std::vector<SquareCoordinate> virtual GetLegalMoves() const;
};

class King : public Piece
{
public:
	const char Symbol = 'K';
	const int value = 10;

	King(Board* board, PieceColor color, unsigned char row, unsigned char col) : Piece(board, color, row, col) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'K' : 'k'; };
	virtual const char* GetName() const { return "King"; }
	std::vector<SquareCoordinate> virtual GetLegalMoves() const;
};

class Knight : public Piece
{
public:
	const char Symbol = 'N';
	const int value = 3;

	Knight(Board* board, PieceColor color, unsigned char row, unsigned char col) : Piece(board, color, row, col) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'N' : 'n'; };
	virtual const char* GetName() const { return "Knight"; }
	std::vector<SquareCoordinate> virtual GetLegalMoves() const;
};

class Pawn : public Piece
{
public:
	const char Symbol = 'P';
	const int value = 1;

	Pawn(Board* board, PieceColor color, unsigned char row, unsigned char col) : Piece(board, color, row, col) {}
	char GetSymbol() const override { return (Color == COLOR_WHITE) ? 'P' : 'p'; };
	virtual const char* GetName() const { return "Pawn"; }
	std::vector<SquareCoordinate> virtual GetLegalMoves() const;
};