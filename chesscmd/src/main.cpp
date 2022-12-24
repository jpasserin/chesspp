#include <iostream>
#include "board.h"

void PlayGame()
{
	Board* board = new Board();

	board->Draw();

	Piece* piece;
	SquareCoordinate square;
	std::string legalSquares;
	for (int i = 0; i < 10; i++)
	{

		piece = board->GetRandomPiece();
		square = piece->GetRandomLegalMove();
		if (square.Valid)
		{
			std::cout << "Move " << piece->Color << *piece << piece->Square.GetName() << " to " << square.GetName() << " (" << legalSquares << ")" << std::endl;
			board->MovePiece(piece, square);
		}
		board->Draw();

		//for (PieceColor color : {COLOR_WHITE, COLOR_BLACK})
		//{
		//	// Get a random piece and its square
		//	piece = board->GetRandomPiece(color);

		//	// Get Legal Moves
		//	legalSquares = "";
		//	for (SquareCoordinate legalSquare : piece->GetLegalMoves())
		//		legalSquares += legalSquare.GetName() + " ";

		//	// Move to Random Square
		//	square = piece->GetRandomLegalMove();
		//	if (square.Valid)
		//	{
		//		std::cout << "Move " << piece->Color << *piece << piece->Square.GetName() << " to " << square.GetName() << " (" << legalSquares << ")" << std::endl;
		//		board->MovePiece(piece, square);
		//	}
		//	board->Draw();
		//}
	}

	delete board;
	std::cout << "Good game!" << std::endl;
}

int main()
{
	PlayGame();
	std::cin.get();
}
