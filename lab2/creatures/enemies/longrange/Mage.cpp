//
// Created by red on 08.12.2021.
//

#include "Mage.h"

void Mage::act(Player &player, Room *room) {
    this->ai->setPlayer(&player);
    this->ai->decisionTree(room, *this);
}

/*
void Mage::heal(Actor &target) { //10 MP = heal price
    int tmp = target.getMaxHP() - (target.getHP() + 10);
    if (tmp > 0) {
        target.heal(tmp);
    } else {
        target.heal(10 + tmp);
    }
    if (tmp) this->baseMP -= 10;
}
*////just an idea