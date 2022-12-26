#pragma once
#include <vector>
#include <QGridLayout>

#include "board.h"
#include "squarebutton.h"

class BoardWidget : public QWidget
{
    std::shared_ptr<Board> mBoard;
    std::vector<SquareButton*> Buttons;

    SquareButton* GetButton(SquareCoordinate square) const;
    void ButtonClicked();
    void MovePiece(Piece* piece, SquareCoordinate square);
public:
    BoardWidget(QWidget* parent = nullptr);
    void PushMeClicked();
};
