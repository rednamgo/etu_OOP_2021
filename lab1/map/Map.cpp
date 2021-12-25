//
// Created by red on 06.12.2021.
//

#include "Map.h"

std::vector<Room*> Map::getMap() {
    return this->rooms;
}

Room &Map::getRoom(int num) {
    return *this->rooms[num];
}

void Map::addRoom(Room *room) {
    this->rooms.push_back(room);
    this->room_cnt++;
}
