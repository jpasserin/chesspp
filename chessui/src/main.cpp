#include "public/mainwindow.h"
#include <QtWidgets/QApplication>
#include <thread>
#include <QDebug>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* ChessWindow = new MainWindow();
    ChessWindow->show();

    return a.exec();
}
