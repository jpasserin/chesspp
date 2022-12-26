#include "../public/mainwindow.h"

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
	QObject::connect(ui.PushMeBTN, &QPushButton::clicked, mBoardWDG, &BoardWidget::PushMeClicked);
	QObject::connect(mBoardWDG, &BoardWidget::PieceMoved, this, &MainWindow::UpdateStatusBar);

	UpdateClock();

	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::UpdateClock));
	timer->start(1000);

}

void MainWindow::UpdateStatusBar(std::string move)
{
	ui.statusBar->showMessage(QString::fromStdString(move), 0);
}

void MainWindow::UpdateClock()
{
	QTime WhiteTime = QTime(0, 0, 0).addMSecs(mBoardWDG->mBoard->GetTimeLeft(COLOR_WHITE));
	QTime BlackTime = QTime(0, 0, 0).addMSecs(mBoardWDG->mBoard->GetTimeLeft(COLOR_BLACK));

	ui.WhiteTE->setTime(WhiteTime);
	ui.BlackTE->setTime(BlackTime);
}


