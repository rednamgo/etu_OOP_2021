//
// Created by red on 11.12.2021.
//

#ifndef REWORKED_OVERLAY_H
#define REWORKED_OVERLAY_H
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include "../Direction.h"
//#include "../../../lab1/map/room/Room.h"

class Room;
class Overlay {
public:
    Overlay(int height, int width, Room *room, std::vector<gridLocation> *goal);
    Overlay(Room *room, std::vector<gridLocation> *goal);
    Overlay() = default;
    ~Overlay();
    void setHeightWidth(Room *room);
    void createArray();
    void setOverlay(std::map<gridLocation, int> distance);
    void setGoalXY(std::vector<gridLocation> xy);
    std::vector<gridLocation> getGoal() {return this->goal;}
    std::pair<int, int> getHeightWidth() {return {this->height, this->width};}
    void getWalls(Room *room);
    [[nodiscard]] std::vector<gridLocation> getNeighbours(gridLocation id) const;
    [[nodiscard]] bool in_bounds(gridLocation id) const;
    [[nodiscard]] bool passable(gridLocation id) const;
    void breadth_first_search(std::vector<gridLocation> start);
    void updateOverlay(int d);
    void print();
    gridLocation& getShortestPath(gridLocation &start);
    int **getOverlay() {return this->overlay;}
    std::map<gridLocation, int> *getLayer() {return &this->layer;}
private:
    int **overlay;
    int height, width;
    std::vector<gridLocation> walls;
    std::vector<gridLocation> goal;
    std::map<gridLocation, int> layer;
};

#endif //REWORKED_OVERLAY_H
