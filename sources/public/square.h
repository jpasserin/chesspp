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

public:
	Square(int row, int col);
	SquareColor Color() const; // Returns the color of the square

	friend std::ostream& operator<<(std::ostream& os, const Square& square);
};