#pragma once
#include <iostream>

class Piece;

enum SquareColor{
	COLOR_LIGHT,
	COLOR_DARK
};

class Square
{
public:
	int Row;
	int Col;

private:
	Piece* CurrentPiece;

public:
	Square(int row, int col);
	SquareColor Color() const;
	bool IsEmpty();
	Piece* GetPiece();
	bool SetPiece(Piece* piece);
	bool RemovePiece();
	friend std::ostream& operator<<(std::ostream& os, const Square& square);
};