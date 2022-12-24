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


	ui.PushMeBTN->connect(ui.PushMeBTN, &QPushButton::clicked, mBoardWDG, &BoardWidget::PushMeClicked);

}

