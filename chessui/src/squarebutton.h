#pragma once
#include <QtWidgets/QPushButton>
#include <QResource>

#include <vector>
#include "ui_qtproject.h"

#include "board.h"


class SquareButton : public QPushButton
{
public:
    const int Row;
    const int Col;
private:
    std::shared_ptr<Board> mBoard;

public:
    SquareButton(std::shared_ptr<Board> mBoard, int row, int col);
    int GetIndex();

    void UpdateIcon();

    void SetLegal(bool legal);
    void SetSelected(bool selected);
};