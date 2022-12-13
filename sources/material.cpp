#include "color.h"

std::shared_ptr<Rook> Material::AddRook()
{
	//Rook* rook = new Rook();
	//Pieces.push_back(rook);

	std::shared_ptr<Rook> rook = std::make_shared<Rook>();


	Pieces.push_back(rook.get());

	return rook;
}