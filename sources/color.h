#pragma once

#include "piece.h"

class Material
{
public:
	std::vector<Piece*> Pieces;

public:
	std::shared_ptr<Rook> AddRook(); // Add a Rool piece to this Color
};