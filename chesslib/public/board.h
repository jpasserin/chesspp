#pragma once
#include <vector>
#include <memory>
#include <chrono>

#include "piece.h"

class Board
{
public:
	const int RowCount; // Number of Rows
	const int ColCount; // Number of Columns
	int ColorTurn; // Which color turn it is
private:
	std::vector<Piece*> Pieces; // Pieces on the board, size = RowCount * ColCount
	std::vector<PieceColor> Colors; // Array of Colors
	std::vector<unsigned int> TimeLeft; // Array of Colors
	std::chrono::milliseconds LastMoveTime;
	bool GameStarted;

public:
	Board();	

	Board(const Board&) = delete; // Prevent copies of the class

	Piece* GetPiece(const int& row, const int& col) const;
	Piece* GetRandomPiece(const PieceColor& color) const;
	Piece* GetRandomPiece() const; // Get random piece from the active color

	template <class PieceClass> bool AddPiece(PieceColor color, int row, int col);
	bool MovePiece(Piece* piece, int row, int col);
	bool MovePiece(Piece* piece, const SquareCoordinate& square);

	unsigned int GetTimeLeft(const PieceColor& color) const;
	unsigned int GetTimeLeft() const;

	void Draw() const;

};