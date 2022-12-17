#include "chessppui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessppUI w;
    w.show();
    return a.exec();
}
