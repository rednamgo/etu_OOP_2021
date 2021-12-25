//
// Created by red on 07.12.2021.
//

#include "Dagger.h"



void Dagger::setEffect(IPotion *potion) {
    this->potion = potion;
}

void Dagger::interact(IEntity *target) { //weapons can interact with players only
    Player *player = dynamic_cast<Player*>(target);
    if (!player) return;
    player->setWeapon(this);
}

int Dagger::getATK() {
    return this->ATK;
}

int Dagger::getRNGE() {
    return this->RNG;
}
