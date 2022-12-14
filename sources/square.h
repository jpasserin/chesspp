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
	int Row; // Row Coordinate of the square
	int Col; // Col Coordinate of the square

private:
	std::shared_ptr<Piece> CurrentPiece; // Piece on the square, if none nullptr

public:
	Square(int row, int col);
	SquareColor Color() const; // Returns the color of the square
	bool IsEmpty() const; // Returns true if there isn't a piece on the square
	std::shared_ptr<Piece> GetPiece() const; // Get a pointer to the current piece
	bool SetPiece(std::shared_ptr<Piece> piece); // Set the current piece
	bool RemovePiece(); // REmove the current piece (set it to nullptr)
	const char* GetSymbol() const;
	friend std::ostream& operator<<(std::ostream& os, const Square& square);
};