//
// Created by red on 14.12.2021.
//

#include "PlayerSearchOverlay.h"
#include "../../../lab1/map/room/Room.h"

PlayerSearchOverlay::PlayerSearchOverlay(Room *room) {
    this->setHeightWidth(room);
    this->createArray();
    this->getWalls(room);
    this->setGoalXY({{room->getEntry().first, room->getEntry().second}});
    this->breadth_first_search(this->getGoal());
}

void PlayerSearchOverlay::flipIntoFleeOverlay() {
    /*for (int i = 0; i < this->getHeightWidth().first; i++) {
        for (int j = 0; j < this->getHeightWidth().second; j++) {
            if (this->getOverlay()[i][j] != 100)
                this->getOverlay()[i][j] *= (-1);
        }
    }*/
    for ( auto &p : *this->getLayer() ) p.second *= (-1);
}

void PlayerSearchOverlay::createOverlay(Room *room) {
    this->setHeightWidth(room);
    this->createArray();
    this->getWalls(room);
    this->setGoalXY({{room->getEntry().first, room->getEntry().second}});
    this->breadth_first_search(this->getGoal());
}
