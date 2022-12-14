#pragma once
#include "piece.h"

class Material
{
public:
	const char* Name;
	std::vector<std::shared_ptr<Piece>> Pieces;

public:
	Material(const char* name) : Name(name) {};
	const char* GetName() const;
	std::shared_ptr<Rook> AddRook(); // Add a Rool piece to this Color
	friend std::ostream& operator<<(std::ostream& os, const Material& material);
};