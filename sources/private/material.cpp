#include "../public/material.h"




const char* Material::GetName() const
{
	return Name;
}

std::vector<Piece*> Material::GetPieces()
{
	return Pieces;
}

Rook* Material::AddRook()
{
	//question: Can I write that in one line?
	// I couldn't find a way to havea constructor taking 'this' as an argument
	//std::shared_ptr<Rook> rook = std::make_shared<Rook>();
	Rook* rook = new Rook();
	rook->SetMaterial(this);

	Pieces.push_back(rook);

	return rook;
}

std::ostream& operator<<(std::ostream& os, const Material& material)
{
	os << material.GetName();
	return os;
}