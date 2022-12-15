#pragma once
#include "piece.h"

class Material
{
public:
	const char* Name;
	std::vector<Piece*> Pieces;

public:
	Material(const char* name) : Name(name) {};

	const char* GetName() const;
	std::vector<Piece*> GetPieces();
	Piece* GetRandomPiece();

	Rook* AddRook(); // Add a Rool piece to this Color
	Bishop* AddBishop(); // Add a Rool piece to this Color
	Queen* AddQueen(); // Add a Rool piece to this Color

	friend std::ostream& operator<<(std::ostream& os, const Material& material);
};