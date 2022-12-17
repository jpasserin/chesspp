#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_chessppui.h"

class ChessppUI : public QMainWindow
{
    Q_OBJECT

public:
    ChessppUI(QWidget *parent = nullptr);
    ~ChessppUI();

private:
    Ui::ChessppUIClass ui;
};
