#pragma once
#include <vector>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include "ui_qtproject.h"

#include "board.h"

class SquareButton : public QPushButton
{
    const int Row;
    const int Col;
    Board* mBoard;
    Piece* mPiece;

public:
    SquareButton(Board* mBoard, int row, int col, QWidget* parent = nullptr);
    int GetIndex();

    void SetPiece(Piece* piece);
    void RemovePiece();

    std::vector<int> GetLegalSquares();
    void SetLegal(bool legal);
    void SetSelected(bool selected);
};