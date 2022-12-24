#pragma once
#include <vector>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include "ui_qtproject.h"

#include "board.h"


#include "squarebutton.h"

class BoardWidget : public QWidget
{
    Board* mBoard;
    std::vector<SquareButton*> Buttons;

public:
    BoardWidget(Board* board, QWidget* parent = nullptr);
    SquareButton* GetButton(SquareCoordinate square);
    void ButtonClicked();
    void PushMeClicked();
    void MovePiece(Piece* piece, SquareCoordinate square);
};
