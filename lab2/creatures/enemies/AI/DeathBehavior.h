//
// Created by red on 18.12.2021.
//

#ifndef REWORKED_DEATHBEHAVIOR_H
#define REWORKED_DEATHBEHAVIOR_H
//#include "../../../tools/Placement.h"
//#include "../../Actor.h"
class IEnemy;
class Placement;

class DeathBehavior {
public:
    void die(Room *room, IEnemy *entity) {
        Placement placer;
        placer.deleteFromRoom(room, entity, {entity->getXY().first, entity->getXY().second});
        entity->setDead(true);
        room->setKillCnt();
        //room->updateEnemyCnt();
    }
};


#endif //REWORKED_DEATHBEHAVIOR_H
