#include "qtproject.h"
#include <QtWidgets/QApplication>

#include "board.h"

int main(int argc, char *argv[])
{

    Board* board = new Board();

    QApplication a(argc, argv);
    QtProject w;
    w.SetLabelText("YEs");
    w.SetLabelText("YEs");
    w.SetBoard(board);
    w.show();
    return a.exec();
}
