#include "qtproject.h"

QtProject::QtProject(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

}

QtProject::~QtProject()
{}


void QtProject::SetLabelText(const char* text)
{
    ui.MyLabel->setText(text);
}


void QtProject::SetBoard(Board* in_board)
{ 
    board = in_board; 

	QGridLayout* layout = (QGridLayout*)ui.MyWidget->layout();

	QPushButton* button;
	for (int row = board->RowCount - 1; row >= 0; row--)
	{
		for (int col = 0; col < board->ColCount; col++)
		{
			button = new QPushButton();
			button->setFixedSize(50, 50);
			if((row * board->ColCount + col)%2 == 0)
				button->setBackgroundRole(QPalette::Dark);
			layout->addWidget(button, row, col);
		}
	}
}
