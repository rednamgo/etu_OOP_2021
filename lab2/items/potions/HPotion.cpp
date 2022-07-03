//
// Created by red on 07.12.2021.
//

#include "HPotion.h"

void HPotion::interact(IEntity *entity) {
    //auto target = dynamic_cast<Player*>(entity);
    /*if (target) {
        target->setPotion(this);
    } else */use(entity);
}

void HPotion::use(IEntity *entity) {
    int tmp = 0;
    auto target = dynamic_cast<Actor*>(entity);
    if (target) {
        tmp = target->getMaxHP() - (target->getHP() + this->healVal);
        if (tmp > 0)
            target->heal(this->healVal);
        else target->heal(this->healVal + tmp);
    }
}
