#include "../public/squarebutton.h"

SquareButton::SquareButton(const std::shared_ptr<Board> board, int row, int col) : mBoard(board), Row(row), Col(col), QPushButton()
{
	setFixedSize(45, 45);
	setAutoExclusive(true);
	setProperty("dark", (Row + Col) % 2 == 0);
	setProperty("legal", false);

	UpdateIcon();

	//button->setText(QString::fromStdString(std::to_string(row * board->ColCount + col)));
	//button->setText(QString::fromStdString(std::to_string(row  + col)));
}

int SquareButton::GetIndex() const
{
	return Row * mBoard->ColCount + Col;
}

void SquareButton::UpdateIcon()
{
	const Piece* piece = mBoard->GetPiece(Row, Col);

	if (piece)
	{
		//Q_INIT_RESOURCE(qtproject);
		
		setCheckable(true);
		std::string path = ":/QtProject/img/";
		std::string name = path + piece->GetName() + "_" + std::to_string(piece->Color) + ".png";

		QPixmap pixmap(QString::fromStdString(name));
		QIcon ButtonIcon(pixmap);
		setIcon(ButtonIcon);
		setIconSize(pixmap.rect().size());
	}
	else
	{
		setCheckable(false);
		setIcon(QIcon());
	}
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