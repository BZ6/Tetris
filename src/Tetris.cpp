#include "Tetris.h"

std::vector<std::vector<Point>> shapes = {
    /*
     * ■■■■
     */
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    /*
     * ■■
     * ■■
     */
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
    /*
     * ■■■
     *  ■
     */
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
    /*
     *  ■■
     * ■■
     */
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    /*
     * ■■
     *  ■■
     */
    {{0, 1}, {1, 1}, {1, 0}, {2, 0}},
    /*
     *  ■
     *  ■
     * ■■
     */
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    /*
     * ■■
     *  ■
     *  ■
     */
    {{1, 0}, {1, 1}, {1, 2}, {0, 2}}
};

Tetris::Tetris() {
    field.resize(FIELD_HEIGHT, std::vector<int>(FIELD_WIDTH, 0));
    srand(time(0));
    newShape();
}

void Tetris::newShape() {
    shape = shapes[rand() % shapes.size()];
    shapeX = FIELD_WIDTH / 2 - 1;
    shapeY = 0;
}

bool Tetris::canMove(int dx, int dy) {
    for (const auto& p : shape) {
        int x = shapeX + p.x + dx;
        int y = shapeY + p.y + dy;
        if (x < 0 || x >= FIELD_WIDTH || y >= FIELD_HEIGHT || (y >= 0 && field[y][x])) {
            return false;
        }
    }
    return true;
}

void Tetris::move(int dx, int dy) {
    if (canMove(dx, dy)) {
        shapeX += dx;
        shapeY += dy;
    }
}

// TODO: надо пофиксить поворот у границ
void Tetris::rotate() {
    std::vector<Point> rotatedShape = shape;
    for (auto& p : rotatedShape) {
        std::swap(p.x, p.y);
        p.x = -p.x;
    }
    if (canMove(0, 0)) {
        shape = rotatedShape;
    }
}

void Tetris::fixShape() {
    for (const auto& p : shape) {
        field[shapeY + p.y][shapeX + p.x] = 1;
    }
    newShape();
    if (!canMove(0, 0)) {
        gameOver = true;
    }
}

void Tetris::removeFullLines() {
    for (int y = FIELD_HEIGHT - 1; y >= 0; --y) {
        bool full = true;
        for (int x = 0; x < FIELD_WIDTH; ++x) {
            if (field[y][x] == 0) {
                full = false;
                break;
            }
        }
        if (full) {
            field.erase(field.begin() + y);
            field.insert(field.begin(), std::vector<int>(FIELD_WIDTH, 0));
            ++y;
        }
    }
}

void Tetris::draw() {
    system("cls");
    for (int y = 0; y < FIELD_HEIGHT; ++y) {
        for (int x = 0; x < FIELD_WIDTH; ++x) {
            std::cout << (field[y][x] ? "#" : ".");
        }
        std::cout << std::endl;
    }
    for (const auto& p : shape) {
        std::cout << "\033[" << shapeY + p.y + 1 << ";" << shapeX + p.x + 1 << "H@";
    }
}

bool Tetris::isGameOver() const {
    return gameOver;
}

void Tetris::update() {
    if (!canMove(0, 1)) {
        fixShape();
        removeFullLines();
    } else {
        move(0, 1);
    }
}
