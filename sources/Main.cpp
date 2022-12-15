#include <iostream>
#include "public/board.h"

void PlayGame()
{
	std::cout << "Let's start a game of chess!" << std::endl;

	// Creates a standard board game
	Board board = Board();

	Material* white = board.GetMaterial(0);

	Piece* randomPiece = white->GetRandomPiece();
	Square* randomSquare = board.GetSquare(randomPiece);

	std::cout << *randomPiece << " - " << randomPiece->PieceMaterial->Name << " - " << *randomSquare << std::endl;

	std::string legalSquares;
	for (Square* legalSquare : randomPiece->GetLegalMoves(&board, randomSquare))
		legalSquares += legalSquare->GetName() + " ";

	std::cout << legalSquares << std::endl;

	for (int i = 0; i < 10; i++)
	{
		randomPiece = white->GetRandomPiece();
		randomSquare = board.GetSquare(randomPiece);
		randomSquare = randomPiece->GetRandomLegalMove(&board, randomSquare);
		std::cout << "Move " << *randomPiece << " to " << *randomSquare << " - ";
		board.MovePiece(randomPiece, randomSquare);

		legalSquares = "";
		for (Square* legalSquare : randomPiece->GetLegalMoves(&board, randomSquare))
			legalSquares += legalSquare->GetName() + " ";
		std::cout << legalSquares << std::endl;
		//Move Piece
	}

	board.Draw();

}

int main()
{

	

	PlayGame();
	std::cin.get();
}
