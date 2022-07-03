//
// Created by red on 08.12.2021.
//

#include "Demon.h"

void Demon::act(Player &player, Room *room) {
    //this->ai->setPlayer(&player);
    this->ai->decisionTree(room, *this);
}
