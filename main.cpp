#include <stdio.h>
#include <termios.h>

#include "2048.h"
#include "PrintfUI.h"

char get1char()
{
    char c;
    /*
    c = getchar();
    while (getchar() != 10);//*/

    system("stty raw");
    c=getchar();
    system("stty cooked"); //*/
    return c;
}


int main()
{
    printf("Run in main\n");
    char inputKey;

    Game2048 game;
    bool run = true;

    while (run) {
        inputKey = get1char();
        switch (inputKey) {
            case 'a':
                printf("Move left:\n");
                game.receivedDirect(Direction::LEFT);
                break;
            case 'w':
                printf("Move up:\n");
                game.receivedDirect(Direction::UP);
                break;
            case 's':
                printf("Move down:\n");
                game.receivedDirect(Direction::DOWN);
                break;
            case 'd':
                printf("Move right:\n");
                game.receivedDirect(Direction::RIGHT);
                break;
            case 'q':
                run = false;
                game.gameOver();
                break;
            default:
                printf("invalid input:%c! expected in {w,a,s,d,q}\n", inputKey);
                break;
        }
    }

    return 0;
}