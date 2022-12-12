#include <iostream>
#include "board.h"

int main()
{
	std::cout << "Let's start a game of chess!" << std::endl;
	
	// Creates a standard board game
	Board board = Board();

	// Get a square (I know there is a piece here)
	Square* square = board.GetSquare(4, 4);
	std::cout << *square << std::endl;
	std::cout << typeid(*square).name() << std::endl;
	
	// Get the piece
	Piece* myPiece = square->GetPiece();
	std::cout << *myPiece << std::endl;

	// Get legal squares to move that piece to
	auto legalSquares = myPiece->GetLegalMove(&board, square);
	std::cout << legalSquares.size() << std::endl;
	
	// Prints out all the legal squares
	for (Square* legalSquare : legalSquares)
		std::cout << *legalSquare << std::endl;

	std::cin.get();
}