#include <cstdlib>
#include <time.h>

#include "../public/piece.h"
#include "../public/board.h"
#include "../public/square.h"

void CheckSquares(const std::vector<std::pair<int, int>>& pairs, Board* board, Material* material, std::vector<Square*>& out)
{
	Square* square;
	Piece* piece;
	for (std::pair<int, int > pair : pairs)
	{
		square = board->GetSquare(pair.first, pair.second);
		piece = board->GetPiece(square);
		if (piece)
		{
			if (piece->PieceMaterial != material)
				out.push_back(square);
			break;
		}
		out.push_back(square);
	}
}

std::vector<Square*> GetDirectionMoves(std::vector<std::pair<int, int>> directions, Board* board, Square* square, Material* material, bool recursive = true)
{
	std::vector<std::pair<int, int>> pairs;
	std::vector<Square*> squares;
	int Row, Col;
	for (std::pair<int, int> dir : directions)
	{
		Row = square->Row + dir.first;
		Col = square->Col + dir.second;

		pairs.clear();
		while ((0 <= Row) && (Row < board->RowCount) && (0 <= Col) && (Col < board->ColCount))
		{
			pairs.push_back({ Row, Col });
			if (!recursive)
				break;

			Row += dir.first;
			Col += dir.second;
		}
		CheckSquares(pairs, board, material, squares);
	}


	return squares;
}

Square* Piece::GetRandomLegalMove(Board* board, Square* square) const
{
	std::vector<Square*> squares = GetLegalMoves(board, square);

	if (squares.size())
	{
		srand(time(0) + rand());
		int index = rand() % squares.size();
		return squares[index];
	}

	return nullptr;
}

std::vector<Square*> Rook::GetLegalMoves(Board* board, Square* square) const
{
	return GetDirectionMoves({ {1,0}, {-1,0}, {0,1}, {0,-1} }, board, square, PieceMaterial);
}

std::vector<Square*> Bishop::GetLegalMoves(Board* board, Square* square) const
{
	return GetDirectionMoves({ {1,1}, {-1,-1}, {1,-1}, {-1,1} }, board, square, PieceMaterial);
}

std::vector<Square*> Queen::GetLegalMoves(Board* board, Square* square) const
{
	return GetDirectionMoves({ {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1} }, board, square, PieceMaterial);
}

std::vector<Square*> King::GetLegalMoves(Board* board, Square* square) const
{
	return GetDirectionMoves({ {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1} }, board, square, PieceMaterial, false);
}

std::vector<Square*> Knight::GetLegalMoves(Board* board, Square* square) const
{
	return GetDirectionMoves({ {2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2} }, board, square, PieceMaterial, false);
}

std::vector<Square*> Pawn::GetLegalMoves(Board* board, Square* square) const
{
	std::vector<std::pair<int, int>> directions = { {1,0}, };
	return GetDirectionMoves(directions, board, square, PieceMaterial, false);
}

std::ostream& operator<<(std::ostream& os, const Piece& piece)
{
	os << typeid(piece).name();
	return os;
}