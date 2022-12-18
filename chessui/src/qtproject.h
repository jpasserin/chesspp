#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include "ui_qtproject.h"

#include "board.h"

class QtProject : public QMainWindow
{
    Q_OBJECT

    Board* board;

public:
    QtProject(QWidget *parent = nullptr);
    ~QtProject();

    void SetLabelText(const char* text);
    void SetBoard(Board* in_board);

private:
    Ui::QtProjectClass ui;
};
