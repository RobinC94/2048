#include "PrintfUI.h"

PrintfUI::PrintfUI() {}

void PrintfUI::setBoard(const Matrix& newBoard) { gameBoard = newBoard; }

void PrintfUI::setMotion(const Direction dire, const Matrix& dist) {}

void PrintfUI::show() {
    int score = 0;
    for (const auto& v : gameBoard) {
        for (const auto& e : v) {
            score += e;
            printf("%5d", e);
        }
        printf("\n");
    }
    printf("Current Score: %d \n", score);
}

PrintfUI::~PrintfUI() {}
