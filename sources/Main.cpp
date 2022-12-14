#include <iostream>
#include "public/board.h"

int main()
{
	std::cout << "Let's start a game of chess!" << std::endl;
	
	// Creates a standard board game
	Board board = Board();

	// Get a square (I know there is a piece here)
	Square* square = board.GetSquare(4, 4);
	std::cout << *square << std::endl;
	
	// Get the piece
	Piece* myPiece = square->GetPiece().get();
	std::cout << *myPiece << *(myPiece->PieceMaterial) << std::endl;

	// Get legal squares to move that piece to
	auto legalSquares = myPiece->GetLegalMoves(&board, square);
	std::cout << legalSquares.size() << std::endl;
	
	// Prints out all the legal squares
	for (Square* legalSquare : legalSquares)
		std::cout << *legalSquare << std::endl;

	board.Draw();

	std::cin.get();
}