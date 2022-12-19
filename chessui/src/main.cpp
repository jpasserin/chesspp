#include "qtproject.h"
#include <QtWidgets/QApplication>

#include "board.h"

int main(int argc, char *argv[])
{

    Board* board = new Board();

    QApplication a(argc, argv);
    MainWindow* widget = new MainWindow(board);
    widget->show();
    return a.exec();
}
