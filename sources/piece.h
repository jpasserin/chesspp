#pragma once
#include <iostream>
#include <vector>

class Square;
class Board;
class Material;

class Piece
/* Abstract Piece class
*/
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

	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const = 0; // Returns the legal squares to move the piece to
	friend std::ostream& operator<<(std::ostream& os, const Piece& piece);
};

class Rook : public Piece
{
public:
	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
};

