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

bool Square::IsEmpty() const
{
	return CurrentPiece == nullptr;
}

std::shared_ptr<Piece> Square::GetPiece() const
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

const char* Square::GetSymbol() const
{
	if (IsEmpty())
		return ".";
	else
		return "X";
}

std::ostream& operator<<(std::ostream& os, const Square& square)
{
	//question? is there a way to format strings?
	// in python I can write f"Square [ {Row} | {Col} ]"
	os << "Square [ " << square.Row << " | " << square.Col << " ]";
	return os;
}