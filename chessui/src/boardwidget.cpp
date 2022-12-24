#include "boardwidget.h"

BoardWidget::BoardWidget(Board* board, QWidget* parent) : mBoard(board), QWidget(parent)
{
	QGridLayout* layout = new QGridLayout();
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setVerticalSpacing(0);
	layout->setHorizontalSpacing(0);
	setLayout(layout);

	Buttons = std::vector<SquareButton*>(board->RowCount * board->ColCount, nullptr);

	SquareButton* button;
	for (int row = board->RowCount - 1; row >= 0; row--)
	{
		for (int col = 0; col < board->ColCount; col++)
		{
			button = new SquareButton(board, row, col);
			layout->addWidget(button, board->RowCount - row, col);
			button->connect(button, &QPushButton::clicked, this, &BoardWidget::ButtonClicked);
			Buttons[row * board->ColCount + col] = button;
		}
	}
}

void BoardWidget::PushMeClicked()
{
	//qDebug() << "Hello";

	Piece* piece = mBoard->GetRandomPiece();
	std::optional<SquareCoordinate> square = piece->GetRandomLegalMove();
	if (square.has_value())
		MovePiece(piece, *square);
}

SquareButton* BoardWidget::GetButton(SquareCoordinate square)
{
	return Buttons[square.Row * mBoard->ColCount + square.Col];
}

void BoardWidget::MovePiece(Piece* piece, SquareCoordinate square)
{
	SquareButton* oldButton = GetButton(piece->Square);
	oldButton->RemovePiece();

	mBoard->MovePiece(piece, square);

	SquareButton* newButton = GetButton(square);
	newButton->SetPiece(piece);
}

void BoardWidget::ButtonClicked()
{
	SquareButton* selectedButton = (SquareButton*)qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
	int selectedIndex = selectedButton->GetIndex();
	std::vector<int> legals = selectedButton->GetLegalSquares();

	for (int i = 0; i < (mBoard->RowCount * mBoard->ColCount); i++)
	{
		if (i == selectedIndex)
			Buttons[i]->SetSelected(true);
		else
		{
			bool isLegal = std::find(legals.begin(), legals.end(), i) != legals.end();
			Buttons[i]->SetLegal(isLegal);
		}
	}
}
