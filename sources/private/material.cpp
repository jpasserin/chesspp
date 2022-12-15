#include "../public/material.h"




const char* Material::GetName() const
{
	return Name;
}

std::vector<Piece*> Material::GetPieces()
{
	return Pieces;
}

Piece* Material::GetRandomPiece()
{
	int index = rand() % Pieces.size();
	return Pieces[index];
}

Piece* Material::AddPiece(Piece* piece)
{
	piece->SetMaterial(this);
	Pieces.push_back(piece);
	return piece;
}

std::ostream& operator<<(std::ostream& os, const Material& material)
{
	os << material.GetName();
	return os;
}