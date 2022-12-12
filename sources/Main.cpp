#include <iostream>
#include "board.h"

int main()
{
	std::cout << "Let's start a game of chess!" << std::endl;

	Board board = Board();
	Square* square = board.GetSquare(4, 4);
	std::cout << *square << std::endl;
	std::cout << typeid(*square).name() << std::endl;
	
	Piece* myPiece = square->GetPiece();
	std::cout << *myPiece << std::endl;

	auto legalSquares = myPiece->GetLegalMove(&board, square);
	std::cout << legalSquares.size() << std::endl;
	
	for (Square* legalSquare : myPiece->GetLegalMove(&board, square))
		std::cout << *legalSquare << std::endl;

	std::cin.get();
}