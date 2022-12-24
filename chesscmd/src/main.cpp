#include <iostream>
#include <optional>

#include "board.h"

void PlayGame()
{
	Board* board = new Board();

	board->Draw();

	Piece* piece;
	std::optional<SquareCoordinate> data;
	std::string legalSquares;
	for (int i = 0; i < 10; i++)
	{

		piece = board->GetRandomPiece();
		data = piece->GetRandomLegalMove();
		if (data.has_value())
		{
			SquareCoordinate& square = *data;
			std::cout << "Move " << piece->Color << *piece << piece->Square.GetName() << " to " << square.GetName() << std::endl;
			board->MovePiece(piece, square);
		}
		board->Draw();
	}

	delete board;
	std::cout << "Good game!" << std::endl;
}

int main()
{
	PlayGame();
	std::cin.get();
}
