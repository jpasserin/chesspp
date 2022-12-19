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
    void SetPiece(Piece* piece);
    void RemovePiece();
    std::vector<SquareCoordinate> GetLegalSquares();
};

class BoardWidget : public QWidget
{
    Board* mBoard;
    std::vector<SquareButton*> Buttons;

public:
    BoardWidget(Board* board, QWidget* parent = nullptr);
    void ButtonClicked();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

    BoardWidget* mBoardWDG;

public:
    MainWindow(Board* board, QWidget* parent = nullptr);

private:
    Ui::MainWindowClass ui;
};