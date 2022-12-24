#pragma once
#include <vector>
#include <QtWidgets/QPushButton>

#include "board.h"
#include "squarebutton.h"

class BoardWidget : public QWidget
{
    std::shared_ptr<Board> mBoard;
    std::vector<SquareButton*> Buttons;

public:
    BoardWidget(QWidget* parent = nullptr);
    SquareButton* GetButton(SquareCoordinate square);
    void ButtonClicked();
    void PushMeClicked();
    void MovePiece(Piece* piece, SquareCoordinate square);
};
