#pragma once
#include <vector>

#include "color.h"
#include "square.h"

class Board
{
public:
	int RowCount; // Number of Rows
	int ColCount; // Number of Columns
private:
	Material Colors[2]; // Whites and Blacks
public:
	std::vector<Square> Squares; // Squares on the board, size = RowCount * ColCount

public:
	Board();	
	Square* GetSquare(int row, int col); // Returns a specific Square ofd the board
};