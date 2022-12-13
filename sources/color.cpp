#include "color.h"

Rook* Material::AddRook()
{
	Rook* rook = new Rook();
	Pieces.push_back(rook);
	return rook;
}