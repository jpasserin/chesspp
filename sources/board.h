#pragma once
#include <vector>

#include "color.h"
#include "square.h"

class Board
{
public:
	int RowCount;
	int ColCount;
private:
	Color Colors[2];
public:
	std::vector<Square> Squares;

public:
	Board();	
	Square* GetSquare(int row, int col);
};