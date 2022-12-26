#include <iostream>
#include <optional>

#include "board.h"

void PlayGame()
{
	std::unique_ptr<Board> board = std::make_unique<Board>();

	board->Draw();

	// question? Is it always better to declare variables outside a loop
	Piece* piece;
	std::optional<SquareCoordinate> square;
	std::string legalSquares;
	for (int i = 0; i < 10; i++)
	{
		piece = board->GetRandomPiece();
		square = piece->GetRandomLegalMove();
		if (square.has_value())
		{
			std::cout << "Move " << piece->Color << *piece << piece->Square.GetName() << " to " << square.value().GetName() << std::endl;
			board->MovePiece(piece, *square);
		}
		board->Draw();
	}

	std::cout << "Good game!" << std::endl;
}

int main()
{
	PlayGame();
	std::cin.get();
}
