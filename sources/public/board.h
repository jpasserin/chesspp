#pragma once
#include <vector>
#include <unordered_map>

#include "material.h"
#include "square.h"

class Board
{
public:
	int RowCount; // Number of Rows
	int ColCount; // Number of Columns
private:
	Material* Materials[2]; // Whites and Blacks
	std::unordered_map<Square*, Piece*> PieceMap;
public:
	std::vector<Square> Squares; // Squares on the board, size = RowCount * ColCount

public:
	Board();	

	Material* GetMaterial(int index) const;
	Square* GetSquare(int row, int col); // Returns a specific Square ofd the board
	Square* GetSquare(Piece* piece); // Returns a specific Square ofd the board
	Piece* GetPiece(Square* square); // Returns a specific Square ofd the board

	bool AddPiece(Piece* piece, Square* square);
	bool MovePiece(Piece* piece, Square* square);

	void Draw();
};