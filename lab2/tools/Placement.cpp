//
// Created by red on 11.12.2021.
//

#include "Placement.h"
#include "../creatures/Actor.h"

void Placement::place(Room *room, IEntity *entity, gridLocation xy) {
    if (room->getTile(xy.x, xy.y)->getType() == FLOOR)
        room->getTile(xy.x, xy.y)->setEntity(entity);
}

/*void Placement::startPlacement(Room *room) {
    for (int i = 0; i < num; i++) {
        if (entities[i].getType() == 0) place(room, &entities[i], {room->getEntry().first, room->getEntry().second});
    //...to place to all
    }
}*/

void Placement::deleteFromRoom(Room *room, IEntity *entity, gridLocation xy) { //delete from tile
    if (room->getTile(xy.x, xy.y)->getEnitity() == entity)
        delete room->getTile(xy.x, xy.y)->getEnitity();
}

void Placement::moveFrom(Room *room, IEntity *entity, gridLocation lastXY, gridLocation newXY) {
    room->getTile(lastXY.x, lastXY.y)->setEntity(nullptr);
    room->getTile(newXY.x, newXY.y)->setEntity(entity);
    auto p = dynamic_cast<Actor*>(entity);
    if (p) p->setXY(newXY.x, newXY.y);
    else return;
}
