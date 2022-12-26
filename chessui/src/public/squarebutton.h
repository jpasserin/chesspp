#pragma once
#include <QPushButton>
#include "ui_mainwindow.h"

#include "board.h"
 
class SquareButton : public QPushButton
{
public:
    const int Row;
    const int Col;
private:
    std::shared_ptr<Board> mBoard;

public:
    SquareButton(const std::shared_ptr<Board> mBoard, int row, int col);
    int GetIndex() const;

    void UpdateIcon();

    void SetLegal(bool legal);
    void SetSelected(bool selected);
};