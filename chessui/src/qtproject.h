#pragma once
#include <vector>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include "ui_qtproject.h"

#include "board.h"


#include "boardwidget.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

    BoardWidget* mBoardWDG;

public:
    MainWindow(Board* board, QWidget* parent = nullptr);

private:
    Ui::MainWindowClass ui;
};