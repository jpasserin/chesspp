#include "qtproject.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	mBoardWDG = new BoardWidget();
	QHBoxLayout* layout = (QHBoxLayout*)ui.MainWDG->layout();
	layout->insertWidget(0, mBoardWDG, Qt::AlignLeft);

	// Connect the Push Button
	ui.PushMeBTN->connect(ui.PushMeBTN, &QPushButton::clicked, mBoardWDG, &BoardWidget::PushMeClicked);
}

