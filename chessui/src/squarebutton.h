#pragma once
#include <vector>
#include <QtWidgets/QPushButton>
#include "ui_qtproject.h"

#include "board.h"


class SquareButton : public QPushButton
{
    const int Row;
    const int Col;
    std::shared_ptr<Board> mBoard;
    Piece* mPiece;

public:
    SquareButton(std::shared_ptr<Board> mBoard, int row, int col);
    int GetIndex();

    void SetPiece(Piece* piece);
    void RemovePiece();

    std::vector<int> GetLegalSquares();
    void SetLegal(bool legal);
    void SetSelected(bool selected);
};