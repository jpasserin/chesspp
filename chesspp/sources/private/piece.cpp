#include <cstdlib>
#include <time.h>

#include "../public/piece.h"
#include "../public/board.h"


void CheckSquares(const std::vector<std::pair<int, int>>& pairs, const Board* board, PieceColor color, std::vector<SquareCoordinate>& out)
{
	SquareCoordinate square;
	Piece* piece;
	for (std::pair<int, int > pair : pairs)
	{
		square = SquareCoordinate(pair.first, pair.second);
		piece = board->GetPiece(square);
		if (piece)
		{
			if (piece->Color != color)
				out.push_back(square);
			break;
		}
		out.push_back(square);
	}
}

std::vector<SquareCoordinate> Piece::GetDirectionMoves(std::vector<std::pair<int, int>> directions, bool recursive = true) const
{
	std::vector<std::pair<int, int>> pairs;
	std::vector<SquareCoordinate> squares;
	int nextRow, nextCol;
	for (std::pair<int, int> dir : directions)
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

SquareCoordinate Piece::GetRandomLegalMove() const
{
	std::vector<SquareCoordinate> squares = GetLegalMoves();

	if (squares.size())
	{
		srand(time(0) + rand());
		int index = rand() % squares.size();
		return squares[index];
	}

	return SquareCoordinate();
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
	std::vector<std::pair<int, int>> directions;
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