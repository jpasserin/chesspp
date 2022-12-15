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
	Square* PieceSquare;
	char Symbol = 'x';

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
	Square* GetRandomLegalMove(Board* board, Square* square) const;
	virtual char GetSymbol() const { return Symbol; };
	friend std::ostream& operator<<(std::ostream& os, const Piece& piece);
};

class Rook : public Piece
{
public:
	char Symbol = 'R';

	char GetSymbol() const override { return Symbol; };
	std::vector<Square*> virtual GetLegalMoves(Board* board, Square* square) const;
};

