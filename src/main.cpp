#include "Tetris.h"
#include "Control.h"

int main() {
    Tetris game;

    while (!game.isGameOver()) {
        game.draw();
        controlByKeyboard(game);
        game.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    std::cout << "Game Over!" << std::endl;
    return 0;
}
