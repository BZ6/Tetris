#include "Control.h"

void controlByKeyboard(Tetris &game) {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                game.move(-1, 0);
                break;
            case 'd':
                game.move(1, 0);
                break;
            case 's':
                game.move(0, 1);
                break;
            case 'w':
                game.rotate();
                break;
        }
    }
}
