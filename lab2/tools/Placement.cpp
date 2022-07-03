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
    /*std::vector<IEntity *> e = room->getEntities();
    if (room->getTile(xy.x, xy.y)->getEnitity() == entity) {
        if (e.size() == 1) {
            e.clear();
        } else if (e.size() > 1) {
            for (int i = 0; i < e.size(); i++) {
                if (e[i] == entity) {
                    e.erase(std::next(e.begin() + i));
                    break;
                }
            }
        }
    } else return;
        //delete room->getTile(xy.x, xy.y)->getEnitity();
        room->getTile(xy.x, xy.y)->removeEntity();
        room->updateEnemyCnt();*/
    room->getTile(xy.x, xy.y)->removeEntity();
}

void Placement::moveFrom(Room *room, IEntity *entity, gridLocation lastXY, gridLocation newXY) {
    Tile *new_tmp = room->getTile(newXY.x, newXY.y);
    Tile *old_tmp = room->getTile(lastXY.x, lastXY.y);
    if (new_tmp->isEmpty() && room->getTile(newXY.x, newXY.y)->canWalk()) {
        new_tmp->setEntity(entity);
        old_tmp->removeEntity();
    } else return;
    //room->getTile(lastXY.x, lastXY.y)->setEntity(nullptr);
    auto p = dynamic_cast<Actor*>(entity);
    if (p) p->setXY(newXY.x, newXY.y);
    else return;
}
