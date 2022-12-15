#include <iostream>
#include "public/board.h"

void PlayGame()
{
	std::cout << "Let's start a game of chess!" << std::endl;

	// Creates a standard board game
	Board board = Board();

	board.Draw();

	// Get the white pieces
	Material* white = board.GetMaterial(0);

	Piece* randomPiece;
	Square* randomSquare;
	std::string legalSquares;

	for (int i = 0; i < 10; i++)
	{
		// Get a random piece and its square
		randomPiece = white->GetRandomPiece();
		randomSquare = board.GetSquare(randomPiece);
		std::cout << *randomPiece << " - " << randomPiece->PieceMaterial->Name << " - " << *randomSquare << std::endl;

		// Get Legal Moves
		legalSquares = "";
		for (Square* legalSquare : randomPiece->GetLegalMoves(&board, randomSquare))
			legalSquares += legalSquare->GetName() + " ";
		std::cout << legalSquares << std::endl;

		// Move to Random Square
		randomSquare = randomPiece->GetRandomLegalMove(&board, randomSquare);
		std::cout << "Move " << *randomPiece << " to " << *randomSquare << std::endl;
		board.MovePiece(randomPiece, randomSquare);

		board.Draw();
	}


}

int main()
{

	

	PlayGame();
	std::cin.get();
}
