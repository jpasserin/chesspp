#include "square.h"

Square::Square(int row, int col): Row(row), Col(col), CurrentPiece(nullptr) {}

SquareColor Square::Color() const
{
	bool isLight = ((Row * Col) % 2) == 1;
	if (isLight)
		return COLOR_LIGHT;
	else
		return COLOR_DARK;
}

bool Square::IsEmpty()
{
	return CurrentPiece == nullptr;
}

std::shared_ptr<Piece> Square::GetPiece()
{
	return CurrentPiece;
}

bool Square::SetPiece(std::shared_ptr<Piece> piece)
{
	if (!IsEmpty())
		return false;
	
	CurrentPiece = piece;
	return true;
}

bool Square::RemovePiece()
{
	if (IsEmpty())
		return false;

	CurrentPiece = nullptr;
	return true;
}

std::ostream& operator<<(std::ostream& os, const Square& square)
{
	os << "Square" << square.Row << square.Col;
	//typeid(piece).name();
	return os;
}