#pragma once

#include "piece.h"

class Color
{
public:
	std::vector<Piece*> Pieces;

public:
	Rook* AddRook(); // Add a Rool piece to this Color
};