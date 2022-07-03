//
// Created by red on 07.05.22.
//

#ifndef REWORKED_RULES_ROOMCLEAR_H
#define REWORKED_RULES_ROOMCLEAR_H
#include "../../lab1/map/room/Room.h"
#include "Presets_roomClear.h"

template<std::string &presetName>
class Rules_roomClear {
public:
    //Rules_roomClear() = default;
    Rules_roomClear(Room &room): _room(room) {};
    ~Rules_roomClear() = default;

    void preset() {
        if (presetName == "ALL_CLEAR") reference = Rules_Presets::allClear(_room);
        else if (presetName == "ENEMIES_CLEAR")
            reference = Rules_Presets::allEnemies(_room);
        else if (presetName == "FULL_HP") reference = Rules_Presets::fullHP(_room);
    }

    bool checkRoomClear(int curr) {
        if (curr == reference) {
            return true;
        } else return false;
    }

    bool win() {
        _room.getTile(_room.getExit().first, _room.getExit().second)->setWalk(true);
        if (presetName == "ENEMIES_CLEAR")
            return checkRoomClear(_room.getKillCnt()) && _room.getPlayer()->getXY() == _room.getExit();
        if (presetName == "FULL_HP") return checkRoomClear(_room.getPlayer()->getHP()) &&
                                                _room.getPlayer()->getXY() == _room.getExit();
        else return false;
    }

    bool lose() {
        return _room.getPlayer()->getHP() <= 0;
    }

private:
    int reference;
    Room &_room;
};


#endif //REWORKED_RULES_ROOMCLEAR_H
