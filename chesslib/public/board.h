#pragma once
#include <vector>
#include <memory>
#include <chrono>

#include "piece.h"

class Board
{
public:
	const unsigned char RowCount; // Number of Rows, Max size 255
	const unsigned char ColCount; // Number of Columns, Max size 255
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

	Piece* GetPiece(const unsigned char& row, const unsigned char& col) const;
	Piece* GetRandomPiece(const PieceColor& color) const;
	Piece* GetRandomPiece() const; // Get random piece from the active color

	template <class PieceClass> bool AddPiece(PieceColor color, unsigned char row, unsigned char col);
	bool MovePiece(Piece* piece, unsigned char row, unsigned char col);
	bool MovePiece(Piece* piece, const SquareCoordinate& square);

	unsigned int GetTimeLeft(const PieceColor& color) const;
	unsigned int GetTimeLeft() const;

	void Draw() const;

};