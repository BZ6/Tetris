#ifndef TETRIS_H
#define TETRIS_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

struct Point {
    int x, y;
};

class Tetris {
public:
    const int FIELD_WIDTH = 10;
    const int FIELD_HEIGHT = 20;

    Tetris();
    void newShape();
    bool canMove(int dx, int dy);
    void move(int dx, int dy);
    void rotate();
    void fixShape();
    void removeFullLines();
    void draw();
    bool isGameOver() const;
    void update();

private:
    std::vector<std::vector<int>> field;
    std::vector<Point> shape;
    int shapeX, shapeY;
    bool gameOver;
};

#endif // TETRIS_H
