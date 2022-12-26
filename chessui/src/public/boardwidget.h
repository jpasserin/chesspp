#pragma once
#include <vector>
#include <QGridLayout>

#include "board.h"
#include "squarebutton.h"

class BoardWidget : public QWidget
{
public:
    std::shared_ptr<Board> mBoard;
private:
    std::vector<SquareButton*> Buttons;

    SquareButton* GetButton(SquareCoordinate square) const;
    void ButtonClicked();
    void MovePiece(Piece* piece, SquareCoordinate square);
public:
    BoardWidget(QWidget* parent = nullptr);
    void PushMeClicked();
};
