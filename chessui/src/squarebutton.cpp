#include "squarebutton.h"

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

int SquareButton::GetIndex()
{
	return Row * mBoard->ColCount + Col;
}


void SquareButton::SetPiece(Piece* piece)
{
	mPiece = piece;
	setCheckable(true);

	std::string path = "D:/Jeremie/Code/References/chesspp/chessui/src/img/";
	std::string name = path + piece->GetName() + "_" + std::to_string(mPiece->Color) + ".png";

	QPixmap pixmap(QString::fromStdString(name));
	QIcon ButtonIcon(pixmap);
	setIcon(ButtonIcon);
	setIconSize(pixmap.rect().size());
}

void SquareButton::RemovePiece()
{
	mPiece = nullptr;
	setCheckable(false);
	setIcon(QIcon());
}


std::vector<int> SquareButton::GetLegalSquares()
{
	std::vector<int> legals;

	for (SquareCoordinate square : mPiece->GetLegalMoves())
		legals.push_back(square.Row * mBoard->ColCount + square.Col);

	return legals;
}

void SquareButton::SetLegal(bool legal)
{
	setProperty("legal", legal);
	setCheckable(legal);
	if (legal)
		setStyleSheet("border-style: solid;	border-width:3px; border-color: rgb(85, 170, 255)");
	else
		setStyleSheet("border-width:0px;");
	//QEvent event(QEvent::StyleChange);
	//QApplication::sendEvent(this, &event);
	//update();
	//updateGeometry();
}

void SquareButton::SetSelected(bool selected)
{
	setProperty("legal", false);
	setCheckable(selected);
	if (selected)
		setStyleSheet("border-style: solid; border-width:3px; border-color: rgb(170, 0, 0)");
	else
		setStyleSheet("border-width:0px;");
}