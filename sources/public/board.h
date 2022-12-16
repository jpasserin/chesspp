#pragma once
#include <vector>
#include <unordered_map>

#include "square.h"
#include "piece.h"

class Board
{
public:
	const int RowCount; // Number of Rows
	const int ColCount; // Number of Columns
private:
	std::vector<Square*> Squares; // Squares on the board, size = RowCount * ColCount
	std::vector<std::vector<Piece*>> Pieces;
	std::unordered_map<Square*, Piece*> PieceMap;

public:
	Board();	

	Square* GetSquare(int row, int col) const; // Returns a specific Square ofd the board
	Square* GetSquare(Piece* piece) const; // Returns a specific Square ofd the board
	Piece* GetPiece(Square* square); // Returns a specific Square ofd the board

	Piece* GetRandomPiece(PieceColor color);

	bool AddPiece(Piece* piece, Square* square, PieceColor color);
	bool MovePiece(Piece* piece, Square* square);

	void Draw();
};