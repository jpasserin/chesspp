#include <iostream>
#include "public/board.h"

void PlayGame()
{
	std::cout << "Let's start a game of chess!" << std::endl;

	// Creates a standard board game
	Board board = Board();

	Material* white = board.GetMaterial(0);
	auto whitePieces = white->GetPieces();
	std::cout << whitePieces.size() << std::endl;

	auto firstPiece = whitePieces[0];
	Square* square = board.GetSquare(firstPiece);

	std::cout << *firstPiece << " - " << firstPiece->PieceMaterial->Name << " - " << *square << std::endl;

	auto legalSquares = firstPiece->GetLegalMoves(&board, square);
	for (Square* legalSquare : legalSquares)
	{
		std::cout << *legalSquare << std::endl;

	}

	for (int i = 0; i < 10; i++)
	{
		//Move Piece
	}

	board.Draw();

}

int main()
{

	

	PlayGame();
	std::cin.get();
}
