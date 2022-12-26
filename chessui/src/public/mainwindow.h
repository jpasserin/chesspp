#pragma once
#include <QMainWindow>

#include "ui_mainwindow.h"
#include "boardwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    BoardWidget* mBoardWDG;

public:
    MainWindow(QWidget* parent = nullptr);

private:
    Ui::MainWindowClass ui;
};