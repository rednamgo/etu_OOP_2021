//
// Created by red on 06.12.2021.
//

#include "MapGenerator.h"

void MapGenerator::generate() {
    if (this->isFromFile) {
        readFromFile();
        return;
    }
    this->map = new Map;
    rngMap();
}

void MapGenerator::rngMap() { //we work with prts cause we don`t want to copy vals from time to time
    Room *room = new Room [this->cnt];
    RoomGenerator rngRoom(&room[0], false);
    map->setCnt(cnt);
    for (int i = 0; i < this->cnt; i++) {
        rngRoom.setRoom(&room[i]);
        rngRoom.generate();
        this->map->addRoom(&room[i]);
    }
    saveInFile("1");
}

void MapGenerator::readFromFile() {

}

void MapGenerator::saveInFile(std::string directory) {
    Room room;
    SaveRoom saver(room);
    saver.setPath("/home/red/Uni/OOP/reworked/lab1/map/savedMaps/" + directory);
    for (int i = 0; i < this->cnt; i++) {
        saver.setFilename(std::to_string(i));
        saver.setRoom(this->map->getRoom(i));
        saver.save();
    }
}
