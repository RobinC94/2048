#pragma once
#include "commonTypes.h"

class Game2048 {
public:
    Game2048();
    ~Game2048() = default;

    void receivedDirect(Direction direct);
    void gameOver();

protected:
    Board boardState;
    bool mergeTiles(Direction direct);
    bool mergeTilesInOneRow(int beginIdx, int endIdx, int iterOffset);
    Matrix getStateAsMatrix();
    bool isGameOver();

};
