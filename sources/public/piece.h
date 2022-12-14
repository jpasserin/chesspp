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
	Material* PieceMaterial;
	const char* Symbol = "x";

	Piece()
	{
		std::cout << "Piece Created" << std::endl;
	}

	~Piece()
	{
		std::cout << "Piece Destroyed" << std::endl;
	}

	void SetMaterial(Material* material)
	{
		PieceMaterial = material;
	}

	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const = 0; // Returns the legal squares to move the piece to
	const char* GetSymbol() const;
	friend std::ostream& operator<<(std::ostream& os, const Piece& piece);
};

class Rook : public Piece
{
public:
	const char* Symbol = "R";

	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
};

