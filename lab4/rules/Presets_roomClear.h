//
// Created by red on 10.05.22.
//

#ifndef REWORKED_PRESETS_ROOMCLEAR_H
#define REWORKED_PRESETS_ROOMCLEAR_H
#include "../../lab1/map/room/Room.h"
#include "../../lab2/creatures/enemies/IEnemy.h"

class Rules_Presets{ //presets for room clear rules: 100%, kill `em all, full HP
public:
    static int allClear(Room &room) {return room.getEntities().size();}
    static int allEnemies(Room &room) {
        return room.getEnemyCnt();
    }
    static int fullHP(Room &room) {return room.getPlayer()->getMaxHP();}
};

#endif //REWORKED_PRESETS_ROOMCLEAR_H
