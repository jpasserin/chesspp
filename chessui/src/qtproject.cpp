#include "qtproject.h"
#include <string>
#include <qdebug.h>

MainWindow::MainWindow(Board* board, QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	mBoardWDG = new BoardWidget(board);
	QHBoxLayout* layout = (QHBoxLayout*)ui.MainWDG->layout();
	layout->insertWidget(0, mBoardWDG, Qt::AlignLeft);

}


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
			//QPushButton* button = new QPushButton("button");

			//button->setFixedSize(45, 45);
			layout->addWidget(button, board->RowCount - row, col);
			button->connect(button, &QPushButton::clicked, this, &BoardWidget::ButtonClicked);

			Buttons[row * board->ColCount + col] = button;
			//connect(button, SIGNAL(clicked()), SLOT(Print()));

			;
		}
	}
}


void BoardWidget::ButtonClicked()
{
	QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
	SquareButton* button = (SquareButton*)buttonSender;
	for (SquareCoordinate square : button->GetLegalSquares())
	{

		qDebug() << square.Row << square.Col;
		SquareButton* other = Buttons[square.Row * mBoard->ColCount + square.Col];

		other->setProperty("legal", true);
		other->repaint();
		qDebug() << square.Row << square.Col;
	}
}


std::vector<SquareCoordinate> SquareButton::GetLegalSquares()
{
	std::vector<SquareCoordinate> squares;

	for (SquareCoordinate square : mPiece->GetLegalMoves())
	{
		squares.push_back(square);
	}
	return squares;
}

SquareButton::SquareButton(Board* board, int row, int col, QWidget* parent) : mBoard(board), Row(row), Col(col), QPushButton(parent)
{
	setFixedSize(45, 45);
	setAutoExclusive(true);
	setProperty("dark", (Row + Col) % 2 == 0);
	setProperty("legal", false);

	mPiece = board->GetPiece(row, col);
	if (mPiece)
		SetPiece(mPiece);

	//button->setText(QString::fromStdString(std::to_string(row * board->ColCount + col)));
	//button->setText(QString::fromStdString(std::to_string(row  + col)));
}

void SquareButton::SetPiece(Piece* piece)
{
	mPiece = piece;
	setCheckable(true);

	std::string path = "D:/Jeremie/Code/References/chesspp/chessui/src/img/";
	std::string name =  path + piece->GetName() + "_" + std::to_string(mPiece->Color) + ".png";

	QPixmap pixmap(QString::fromStdString(name));
	QIcon ButtonIcon(pixmap);
	setIcon(ButtonIcon);
	setIconSize(pixmap.rect().size());
}

void SquareButton::RemovePiece()
{
	mPiece = nullptr;
	setCheckable(false);
}
