//
// Created by red on 07.05.22.
//

#ifndef REWORKED_RULES_MAPCLEAR_H
#define REWORKED_RULES_MAPCLEAR_H
#include "../../lab1/map/Map.h"
//#include "Rules_roomClear.h"
//check only when player tries to leave room i.e. check MAP CLASS for room counter

class Rules_mapClear {
public:
    explicit Rules_mapClear(Map &init): map(init) {this->lastRoom = false;}
    ~Rules_mapClear()= default;
    void check(Room &room) {
        if (room.getNum() == this->map.getRoomCnt()) this->lastRoom = true;
        else this->lastRoom = false;
    }
    bool isFinish() const {return lastRoom;}
private:
    Map &map;
    bool lastRoom;
};

#endif //REWORKED_RULES_MAPCLEAR_H
