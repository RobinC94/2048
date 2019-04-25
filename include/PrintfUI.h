#pragma once
#include "BaseUI.h"
class PrintfUI : public BaseUI {
public:
    PrintfUI();
    virtual void setBoard(const Matrix& newState);
    virtual void setMotion(const Direction dire, const Matrix& dist);
    virtual void show();
    ~PrintfUI();

private:
    Matrix gameBoard;
};
