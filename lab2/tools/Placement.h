//
// Created by red on 11.12.2021.
//

#ifndef REWORKED_PLACEMENT_H
#define REWORKED_PLACEMENT_H
#include "../IEntity.h"
#include "../../lab1/map/room/Room.h"
#include "Direction.h"

class Placement {
public:
    Placement() = default;
    Placement(IEntity *entity): entities(entity) {};
    ~Placement() = default;
    void place(Room *room, IEntity *entity, gridLocation xy);
    void moveFrom(Room *room, IEntity *entity, gridLocation lastXY, gridLocation newXY);
    //void startPlacement(Room *room);
    void deleteFromRoom(Room *room, IEntity *entity, gridLocation xy);
private:
    IEntity *entities;
    int num;
};

#endif //REWORKED_PLACEMENT_H
