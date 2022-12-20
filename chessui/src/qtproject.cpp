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
			layout->addWidget(button, board->RowCount - row, col);
			button->connect(button, &QPushButton::clicked, this, &BoardWidget::ButtonClicked);
			Buttons[row * board->ColCount + col] = button;
		}
	}
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

int SquareButton::GetIndex()
{
	return Row * mBoard->ColCount + Col;
}

std::vector<int> SquareButton::GetLegalSquares()
{
	std::vector<int> legals;

	for (SquareCoordinate square : mPiece->GetLegalMoves())
		legals.push_back(square.Row * mBoard->ColCount + square.Col);

	return legals;
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