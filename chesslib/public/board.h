#pragma once
#include <vector>

#include "piece.h"

class Board
{
public:
	const int RowCount; // Number of Rows
	const int ColCount; // Number of Columns
private:
	std::vector<Piece*> Pieces; // Pieces on the board, size = RowCount * ColCount
	int ColorTurn; // Which color turn it is
	std::vector<PieceColor> Colors; // Array of Colors

public:
	Board();	

	Piece* GetPiece(int row, int col) const;
	Piece* GetRandomPiece(PieceColor color) const;
	Piece* GetRandomPiece() const; // Get random piece from the active color

	template <class PieceClass> bool AddPiece(PieceColor color, int row, int col);
	bool MovePiece(Piece* piece, int row, int col);
	bool MovePiece(Piece* piece, SquareCoordinate square);


	void Draw();
};