#pragma once
#include <vector>
#include <unordered_map>

#include "square.h"
#include "piece.h"

class Board
{
public:
	int RowCount; // Number of Rows
	int ColCount; // Number of Columns
private:
	std::unordered_map<Square*, Piece*> PieceMap;
public:
	std::vector<std::vector<Piece*>> Pieces;
	std::vector<Square> Squares; // Squares on the board, size = RowCount * ColCount

public:
	Board();	

	Square* GetSquare(int row, int col); // Returns a specific Square ofd the board
	Square* GetSquare(Piece* piece); // Returns a specific Square ofd the board
	Piece* GetPiece(Square* square); // Returns a specific Square ofd the board

	Piece* GetRandomPiece(PieceColor color) const;

	bool AddPiece(Piece* piece, Square* square, PieceColor color);
	bool MovePiece(Piece* piece, Square* square);

	void Draw();
};