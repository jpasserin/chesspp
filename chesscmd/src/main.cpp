#include <iostream>
#include <optional>

#include "board.h"

static size_t memorySize = 0;
static size_t allocCount = 0;

void* operator new(size_t size)
{
	//std::cout << "Alloc " << size << std::endl;
	memorySize += size;
	allocCount++;
	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	//std::cout << "Free " << size << std::endl;
	memorySize -= size;
	allocCount--;
	free(memory);
}

void printMemory()
{

	std::cout << "Allocs: " << allocCount << " - " << memorySize << "bytes" << std::endl;
}

void PlayGame()
{
	std::unique_ptr<Board> board = std::make_unique<Board>();

	printMemory();
	//board->Draw();

	// question? Is it always better to declare variables outside a loop
	Piece* piece;
	std::optional<SquareCoordinate> square;
	for (int i = 0; i < 10; i++)
	{
		piece = board->GetRandomPiece();
		square = piece->GetRandomLegalMove();
		if (square.has_value())
		{
			std::cout << "Move " << piece->Color << *piece << piece->Square.GetName() << " to " << square.value().GetName() << std::endl;
			board->MovePiece(piece, *square);
		}
		//board->Draw();
		printMemory();
	}

	std::cout << "Good game!" << std::endl;
}


int main()
{
	PlayGame();
	std::cin.get();
}
