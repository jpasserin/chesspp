#pragma once
#include <iostream>
#include <vector>

class Square;
class Board;

class Piece
{

public:
	Piece() 
	{
		std::cout << "Piece Created" << std::endl;
	}

	~Piece()
	{
		std::cout << "Piece Destroyed" << std::endl;
	}

	std::vector<Square*> virtual GetLegalMove(Board* board, Square* square) = 0;
	friend std::ostream& operator<<(std::ostream& os, const Piece& piece);
};

class Rook : public Piece
{
public:
	std::vector<Square*> virtual GetLegalMove(Board* board, Square* square);
};

