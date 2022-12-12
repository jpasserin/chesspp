#include "color.h"

Rook* Color::AddRook()
{
	Rook* rook = new Rook();
	Pieces.push_back(rook);
	return rook;
}