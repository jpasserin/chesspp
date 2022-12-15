#include <iostream>
#include "public/board.h"

void PlayGame()
{
	std::cout << "Let's start a game of chess!" << std::endl;

	// Creates a standard board game
	Board board = Board();

	board.Draw();

	Piece* randomPiece;
	Square* randomSquare;
	std::string legalSquares;
	for (int i = 0; i < 10; i++)
	{
		// Get a random piece and its square
		randomPiece = board.GetRandomPiece(COLOR_WHITE);
		randomSquare = board.GetSquare(randomPiece);
		std::cout << *randomPiece << " - " << randomPiece->Color << " - " << *randomSquare << std::endl;

		// Get Legal Moves
		legalSquares = "";
		for (Square* legalSquare : randomPiece->GetLegalMoves(&board, randomSquare))
			legalSquares += legalSquare->GetName() + " ";
		std::cout << legalSquares << std::endl;

		// Move to Random Square
		randomSquare = randomPiece->GetRandomLegalMove(&board, randomSquare);
		if (randomSquare)
		{
			std::cout << "Move " << *randomPiece << " to " << *randomSquare << std::endl;
			board.MovePiece(randomPiece, randomSquare);
		}

		board.Draw();
	}

	std::cout << "Good game!" << std::endl;

}

void LoopPairs(const std::vector<std::pair<int, int>>& pairs, std::vector<int>& out)
{
	for (std::pair<int, int > pair : pairs)
	{
		out.push_back(pair.first);
	}
}



int main()
{



	PlayGame();
	std::cin.get();
}
