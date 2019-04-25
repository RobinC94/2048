#pragma once
#include "commonTypes.h"
class BaseUI {
public:
    BaseUI();
    virtual void setBoard(const Matrix& newBoard) = 0;
    virtual void setMotion(const Direction dire, const Matrix& dist) = 0;
    virtual void show() = 0;
    virtual ~BaseUI();
};
