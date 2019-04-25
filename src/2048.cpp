// 2048.cpp : Defines the entry point for the console application.
//

#include "2048.h"

#include <algorithm>
#include <random>

#include "PrintfUI.h"
#include "commonTypes.h"

Game2048::Game2048() {
    boardState.resize(ROW_COUNT*COL_COUNT, 0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> distPos(0, ROW_COUNT*COL_COUNT-1);
    size_t randomIdx = distPos(gen);
    boardState[randomIdx] = 2;

    printf("Game start!\n");
    printf("Use w a s d to move, q to exit.\n");
    printf("Enjoy!\n");

    PrintfUI ui;
    auto matrix = getStateAsMatrix();
    ui.setBoard(matrix);
    ui.show();
}

void Game2048::receivedDirect(Direction direct) {
    // modify state according to direct.
    bool moved = mergeTiles(direct);

    // random 2 or 4.
    if (moved) {
        std::vector<int> zeroPos;
        for (int i = 0; i < ROW_COUNT * COL_COUNT; ++i) {
            if (boardState[i] == 0)
                zeroPos.push_back(i);
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distPosIdx(0, zeroPos.size()-1);
        std::uniform_int_distribution<int> distNum(0, 2);
        int randomIdx = distPosIdx(gen);
        //printf("zerosize:%d\n", zeroPos.size());
        //printf("new pos:%d\n", randomIdx);
        if (randomIdx > 15 || randomIdx < 0) randomIdx = 0;
        if (distNum(gen) == 0)
            boardState[zeroPos[randomIdx]] = 4;
        else
            boardState[zeroPos[randomIdx]] = 2;
    }

    // show new state
    PrintfUI ui;
    auto matrix = getStateAsMatrix();
    ui.setBoard(matrix);
    ui.show();

    // judge game state
    if (isGameOver())
        gameOver();
}

bool Game2048::mergeTiles(Direction direct) {
    int iterOffset, lineOffset;
    int begin;
    switch (direct) {
        case Direction::LEFT :
            iterOffset = 1;
            lineOffset = 4;
            begin = 0;
            break;
        case Direction::RIGHT :
            iterOffset = -1;
            lineOffset = 4;
            begin = 3;
            break;
        case Direction::UP :
            iterOffset = 4;
            lineOffset = 1;
            begin = 0;
            break;
        case Direction::DOWN :
            iterOffset = -4;
            lineOffset = 1;
            begin = 12;
            break;
    }
    bool moved = false;
    for (int i = 0; i < ROW_COUNT; ++i) {
        moved |= mergeTilesInOneRow(begin, begin+ROW_COUNT*iterOffset, iterOffset);
        begin += lineOffset;
    }
    return moved;
}

bool Game2048::mergeTilesInOneRow(int beginIdx, int endIdx, int iterOffset)
{
    bool moved = false;
    int numberEndIdx = beginIdx;
    for (int i = beginIdx; i != endIdx; i += iterOffset) {
        int &currentTile = boardState[i];
        int &numberEnd = boardState[numberEndIdx];
        if (currentTile == 0) {
            continue;
        }
        else {
            if (i == numberEndIdx) {
                continue;
            }
            if (currentTile == numberEnd) {
                numberEnd *= -2;
                currentTile = 0;
                numberEndIdx += iterOffset;
                moved = true;
                continue;
            }
            if (numberEnd == 0) {
                numberEnd = currentTile;
                currentTile = 0;
                moved = true;
                continue;
            }
            numberEndIdx += iterOffset;
            if (i != numberEndIdx) {
                boardState[numberEndIdx] = currentTile;
                currentTile = 0;
                moved = true;
            }
        }
    }
    for (int i = beginIdx; i != endIdx; i += iterOffset){
        if (boardState[i] < 0)
            boardState[i] *= -1;
    }
    return moved;
}

Matrix Game2048::getStateAsMatrix()
{
    Matrix matrix;
    for (int i = 0; i < ROW_COUNT*COL_COUNT; i+= COL_COUNT) {
        BoardRow oneRow(boardState.begin() +i , boardState.begin() + i + COL_COUNT);

        matrix.push_back(oneRow);
    }
    return matrix;
}

bool Game2048::isGameOver()
{
    for (int i = 0; i < ROW_COUNT*COL_COUNT; ++i) {
        if (boardState[i] == 0)
            return false;
        if (i < 12) {
            if (boardState[i] == boardState[i+4])
                return false;
        }
        if (i % 4 != 3) {
            if (boardState[i] == boardState[i + 1])
                return false;
        }
    }
    return true;
}

void Game2048::gameOver()
{
    printf("Game Over!!!\n");
    auto maxPosition = std::max_element(boardState.begin(), boardState.end());
    int sum = std::accumulate(boardState.begin() , boardState.end(), 0);
    printf("Your score is %d, largest number is %d.\n", sum, *maxPosition);
    exit(0);
}


