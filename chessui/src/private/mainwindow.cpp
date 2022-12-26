#include "../public/mainwindow.h"
#include <thread>

#include <QDebug>
#include <QTimer>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	mBoardWDG = new BoardWidget();
	QHBoxLayout* layout = (QHBoxLayout*)ui.MainWDG->layout();
	layout->insertWidget(0, mBoardWDG, Qt::AlignLeft);

	// Connect the Push Button
	ui.PushMeBTN->connect(ui.PushMeBTN, &QPushButton::clicked, mBoardWDG, &BoardWidget::PushMeClicked);

	UpdateClock();

	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::UpdateClock));
	timer->start(1000);

}

void MainWindow::UpdateClock()
{
	QTime WhiteTime = QTime(0, 0, 0).addMSecs(mBoardWDG->mBoard->GetTimeLeft(COLOR_WHITE));
	QTime BlackTime = QTime(0, 0, 0).addMSecs(mBoardWDG->mBoard->GetTimeLeft(COLOR_BLACK));

	ui.WhiteTE->setTime(WhiteTime);
	ui.BlackTE->setTime(BlackTime);
}


