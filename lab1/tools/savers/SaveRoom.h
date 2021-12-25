//
// Created by red on 06.12.2021.
//

#ifndef REWORKED_SAVEROOM_H
#define REWORKED_SAVEROOM_H
#include "ISaver.h"
#include <vector>
#include <fstream>
#include "../../map/room/Room.h"

class SaveRoom: ISaver {
public:
    explicit SaveRoom(Room &room): room(room) {};
    ~SaveRoom() = default;
    void save() override;
    void convert();
    void setPath(std::string newpath) {this->path = newpath;}
    void setFilename(std::string name) {this->filename = name;}
    void setRoom(Room &room) {this->room = room;}
    void clearData();
private:
    Room &room;
    std::string path;
    std::string filename;
    std::vector<std::string> data;
};


#endif //REWORKED_SAVEROOM_H
