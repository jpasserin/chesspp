#include "qtproject.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* widget = new MainWindow();
    widget->show();
    return a.exec();
}
