//
// Created by red on 06.12.2021.
//

#ifndef REWORKED_MAP_H
#define REWORKED_MAP_H
#include "room/Room.h"
#include <vector>

class Map {
public:
    Map() = default;
    ~Map() = default;
    std::vector<Room*> getMap();
    Room& getRoom(int num);
    void addRoom(Room *room);
    void setCnt(int val) {this->room_cnt = val;}
    int getRoomCnt() const {return this->room_cnt;}
private:
    std::vector<Room*> rooms;
    int room_cnt;
};


#endif //REWORKED_MAP_H
