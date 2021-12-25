//
// Created by red on 11.12.2021.
//

#include "Overlay.h"
#include "../../../lab1/map/room/Room.h"

Overlay::Overlay(int height, int width, Room *room, std::vector<gridLocation> *goal): height(height), width(width),
goal(*goal){
    createArray();
    getWalls(room);
    breadth_first_search(*goal);
}

Overlay::Overlay(Room *room, std::vector<gridLocation> *goal) {
    this->height = room->getHeightWidth().first;
    this->width = room->getHeightWidth().second;
    this->goal = *goal;
    createArray();
    getWalls(room);
    breadth_first_search(*goal);
}

Overlay::~Overlay() {
    for (int i = 0; i < height; i++)
        delete [] overlay[i];
    delete [] overlay;
}

void Overlay::setGoalXY(std::vector<gridLocation> xy) {
    this->goal = xy;
}

void Overlay::setHeightWidth(Room *room) {
    this->height = room->getHeightWidth().first;
    this->width = room->getHeightWidth().second;
    createArray();
    getWalls(room);
    breadth_first_search(goal);
}

void Overlay::createArray() {
    this->overlay = new int * [height];
    for (int i = 0; i < height; i++)
        this->overlay[i] = new int [width];
}

std::vector<gridLocation> Overlay::getNeighbours(gridLocation id) const {
    std::vector<gridLocation> result;
    for (gridLocation dir : DIR) {
        gridLocation next{id.x + dir.x, id.y + dir.y};
        if (in_bounds(next) && passable(next)) {
            result.push_back(next);
        }
    }

    if ((id.x + id.y) % 2 == 0) {
        //when 0: return the Down, Up, Left, Right neighbors
        //when 1: return the Right, Left, Up, Down neighbors
        //The result is the path alternating between vertical and horizontal steps: move diagonally
        std::reverse(result.begin(), result.end());
    }
    return result;
}

void Overlay::getWalls(Room *room) {
    gridLocation tmp = {0, 0};
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (room->getTile(i, j)->getType() == WALL || room->getTile(i, j)->getType() == ENTRANCE ||
                    room->getTile(i, j)->getType() == EXIT) {
                tmp = {i, j};
                this->walls.push_back(tmp);
            }
        }
    }
}

bool Overlay::in_bounds(gridLocation id) const {
    return 0 <= id.x && id.x < height && 0 <= id.y && id.y < width;
}

bool Overlay::passable(gridLocation id) const {
    for (auto wall : walls) {
        if (wall.x == id.x && wall.y == id.y)
            return false;
    }
    return true;
}

bool operator == (gridLocation a, gridLocation b) {
    return a.x == b.x && a.y == b.y;
}

gridLocation& operator += (gridLocation &a, gridLocation &b) {
    a.x += b.x; a.y += b.y;
    return a;
}

bool operator > (gridLocation a, gridLocation b) {
    return std::tie(a.x, a.y) > std::tie(b.x, b.y);
}

bool operator != (gridLocation a, gridLocation b) {
    return !(a == b);
}

/*bool operator < (gridLocation a, gridLocation b) {
    return std::tie(a.x, a.y) < std::tie(b.x, b.y);
}*/



void Overlay::breadth_first_search(std::vector<gridLocation> start) {
    std::queue<gridLocation> frontier;
    std::map<gridLocation, int> distance;
    for (gridLocation s: start) {
        frontier.push(s);
        distance[s] = 0;
    }

    gridLocation current = {0, 0};

    while (!frontier.empty()) {
        current = frontier.front();
        frontier.pop();

        for (gridLocation next: getNeighbours(current)) {
            if (distance.find(next) == distance.end()) {
                frontier.push(next);
                distance[next] = 1 + distance[current];
            }
        }
    }
    this->layer = distance;
    setOverlay(distance);
}

void Overlay::setOverlay(std::map<gridLocation, int> distance) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (passable({i, j}))
                overlay[i][j] = distance[{i, j}];
            else overlay[i][j] = 100;
        }
    }
}

void Overlay::print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << layer[{i, j}] << " ";
        }
        std::cout << std::endl;
    }
}

void Overlay::updateOverlay(int d) {
    Direction dir;
    gridLocation tmp = dir.getDir(d);
    for (auto & i : goal) {
        i += tmp;
    }
    breadth_first_search(goal);
}

gridLocation &Overlay::getShortestPath(gridLocation &start) {
    gridLocation *result = new gridLocation{start.x, start.y};
    std::vector<gridLocation> neighbours = this->getNeighbours(*result);
    for (auto & neighbour : neighbours) {
        if (layer[neighbour] < layer[*result])
            *result = neighbour;
    }
    return *result;
}
