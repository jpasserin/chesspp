#include <iostream>
#include "public/board.h"

void PlayGame()
{
	Board* board = new Board();

	board->Draw();

	Piece* piece;
	SquareCoordinate square;
	std::string legalSquares;
	for (int i = 0; i < 10; i++)
	{
		for (PieceColor color : {COLOR_WHITE, COLOR_BLACK})
		{
			// Get a random piece and its square
			piece = board->GetRandomPiece(color);

			// Get Legal Moves
			legalSquares = "";
			for (SquareCoordinate legalSquare : piece->GetLegalMoves())
				legalSquares += legalSquare.GetName() + " ";

			// Move to Random Square
			square = piece->GetRandomLegalMove();
			if (square.Valid)
			{
				std::cout << "Move " << piece->Color << *piece << piece->Square.GetName() << " to " << square.GetName() << " (" << legalSquares << ")" << std::endl;
				board->MovePiece(piece, square);
			}
			board->Draw();
		}

	}

	delete board;
	std::cout << "Good game!" << std::endl;

}

class Parent;


class Child
{
	const Parent* parent;
	const int age;

public:
	Child(Parent* p, int a) : parent(p), age(a)
	{
		std::cout << "Create Child" << std::endl;
	}
};

class Son : public Child
{
public:
	Son(Parent* p, int a) : Child(p, a) {}
}; 

class Daughter : public Child
{
public:
	Daughter(Parent* p, int a) : Child(p, a) {}
};

class Parent
{
	std::vector<Child*> children;

public:
	Parent()
	{
		children = std::vector<Child*>(2, nullptr);

		Child* son = new Son(this, 12);
		children[0] = son;
		Child* daughter = new Daughter(this, 8);
		children[1] = daughter;

		std::cout << "Create Parent" << std::endl;
	}
	~Parent()
	{
		std::cout << "Destroy Parent" << std::endl;
	}
};


int main()
{
	//Parent dad = Parent();

	PlayGame();
	std::cin.get();
}
