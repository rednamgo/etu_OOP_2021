//
// Created by red on 08.12.2021.
//

#include "Poison.h"

void Poison::interact(IEntity *entity) { //can interact with actors and weapons only
    auto target = dynamic_cast<Player*>(entity);
    if (target) {
        target->setPotion(this);
    } else use(entity);
}

void Poison::use(IEntity *entity) {
    auto target = dynamic_cast<Actor*>(entity);
    if (target) {
        target->getDMG(this->DMGVal*turns);
    } else if (auto weapon = dynamic_cast<IWeapon*>(entity)) {
        weapon->setEffect(this);
    } else return;
}
