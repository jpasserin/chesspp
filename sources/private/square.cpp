
#include "../public/square.h"

const char* ALPHABET = "abcdefghijklmnopqrstuvwxyz";

Square::Square(int row, int col): Row(row), Col(col) {}

SquareColor Square::Color() const
{
	bool isLight = ((Row * Col) % 2) == 1;
	if (isLight)
		return COLOR_LIGHT;
	else
		return COLOR_DARK;
}

std::string Square::GetName() const
{
	return std::string(1, ALPHABET[Col]) + std::to_string(Row + 1);
}

std::ostream& operator<<(std::ostream& os, const Square& square)
{
	//question? is there a way to format strings?
	// in python I can write f"Square [ {Row} | {Col} ]"
	//os << "Square [ " << square.Row << " | " << square.Col << " ]";
	os << "Square [ " << square.GetName() << " ]";
	return os;
}