//
// Created by red on 08.12.2021.
//

#ifndef REWORKED_DIRECTION_H
#define REWORKED_DIRECTION_H
#include <vector>
#include <tuple>

enum directions {
    UP = 1,
    DOWN = 2,
    RIGHT = 3,
    LEFT = 4
};

struct gridLocation {
    int x;
    int y;
    bool operator < (const gridLocation &a) const {
        return std::tie(a.x, a.y) < std::tie(this->x, this->y);
    }
};

const std::vector<gridLocation> DIR = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

class Direction {
public:
    Direction() = default;
    ~Direction() = default;
    gridLocation getDir(int d) {
        switch (d) {
            case UP:
                return up;
            case DOWN:
                return down;
            case RIGHT:
                return right;
            case LEFT:
                return left;
        }
        return {0, 0};
    }

private:
    gridLocation up = DIR[0];
    gridLocation down = DIR[1];
    gridLocation right = DIR[2];
    gridLocation left = DIR[3];
};

#endif //REWORKED_DIRECTION_H
