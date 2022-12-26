#include <cstdlib>
#include <time.h>

#include "../public/piece.h"
#include "../public/board.h"


// 'static' means this function can only be used in this module
static void CheckSquares(const std::vector<std::pair<unsigned char, unsigned char>>& pairs, const Board* board, PieceColor color, std::vector<SquareCoordinate>& out)
// This function check if the squares in a specific direction are empty or not, if not it checks the color of the piece on that square
{
	const Piece* piece;
	for (std::pair<unsigned char, unsigned char > pair : pairs)
	{
		piece = board->GetPiece(pair.first, pair.second);
		if (piece)
		{
			if (piece->Color != color)
				out.push_back({ pair.first, pair.second });
			break;
		}
		out.push_back({ pair.first, pair.second });
	}
}

std::vector<SquareCoordinate> Piece::GetDirectionMoves(const std::vector<std::pair<char, char>> directions, bool recursive = true) const
{
	std::vector<std::pair<unsigned char, unsigned char>> pairs;
	std::vector<SquareCoordinate> squares;
	int nextRow, nextCol;
	for (std::pair<char, char> dir : directions)
	{
		nextRow = Square.Row + dir.first;
		nextCol = Square.Col + dir.second;

		pairs.clear();
		while ((0 <= nextRow) && (nextRow < mBoard->RowCount) && (0 <= nextCol) && (nextCol < mBoard->ColCount))
		{
			pairs.push_back({ nextRow, nextCol });
			if (!recursive)
				break;

			nextRow += dir.first;
			nextCol += dir.second;
		}
		CheckSquares(pairs, mBoard, Color, squares);
	}

	return squares;
}

// Question? optional is a c++17 feature
// what version of c++ is used in UE
// Is that a good use of optional?
std::optional<SquareCoordinate> Piece::GetRandomLegalMove() const
{
	std::vector<SquareCoordinate> squares = GetLegalMoves();

	if (squares.size())
	{
		srand(time(0) + rand());
		int index = rand() % squares.size();
		return squares[index];
	}

	return {};
}

std::vector<SquareCoordinate> Rook::GetLegalMoves() const
{
	return GetDirectionMoves({ {1,0}, {-1,0}, {0,1}, {0,-1} });
}

std::vector<SquareCoordinate> Bishop::GetLegalMoves() const
{
	return GetDirectionMoves({ {1,1}, {-1,-1}, {1,-1}, {-1,1} });
}

std::vector<SquareCoordinate> Queen::GetLegalMoves() const
{
	return GetDirectionMoves({ {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1} });
}

std::vector<SquareCoordinate> King::GetLegalMoves() const
{
	return GetDirectionMoves({ {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1} }, false);
}

std::vector<SquareCoordinate> Knight::GetLegalMoves() const
{
	return GetDirectionMoves({ {2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2} }, false);
}

std::vector<SquareCoordinate> Pawn::GetLegalMoves() const
{
	std::vector<std::pair<char, char>> directions;
	if (Color == COLOR_WHITE)
		directions = { {1,0}, };
	else
		directions = { {-1,0}, };
	return GetDirectionMoves(directions, false);
}

std::ostream& operator<<(std::ostream& os, const Piece& piece)
{
	os << typeid(piece).name();
	return os;
}