#pragma once
#include <vector>
#include <unordered_map>

#include "piece.h"

class Board
{
public:
	const int RowCount; // Number of Rows
	const int ColCount; // Number of Columns
private:
	std::vector<Piece*> Pieces; // Squares on the board, size = RowCount * ColCount

public:
	Board();	

	Piece* GetPiece(int row, int col) const;
	Piece* GetPiece(SquareCoordinate square) const;
	Piece* GetRandomPiece(PieceColor color) const;

	bool AddPiece(Piece* piece);
	bool MovePiece(Piece* piece, int row, int col);
	bool MovePiece(Piece* piece, SquareCoordinate square);

	void Draw();
};