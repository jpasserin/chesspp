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

	Piece* AddPiece(Piece*);

	friend std::ostream& operator<<(std::ostream& os, const Material& material);
};