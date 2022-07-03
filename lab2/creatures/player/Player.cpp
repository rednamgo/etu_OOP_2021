//
// Created by red on 07.12.2021.
//

#include "Player.h"

void Player::die(Room *room) {
    Placement placer{};
    placer.moveFrom(room, this, this->getLocation(), {room->getEntry().first, room->getEntry().second});
    this->baseMP = MPcap; //restore HP and MP and return to start of room if HP <= 0
    this->baseHP = HPcap;
}

void Player::move(int direction, Room *room) {
    IEntity *tmp;
    Item *i_tmp;
    Direction dir;
    Placement placer{};
    if (room->getTile(this->getXY().first + dir.getDir(direction).x, this->getXY().second + dir.getDir(direction).y)->canWalk())
        if (room->getTile(this->getXY().first + dir.getDir(direction).x, this->getXY().second + dir.getDir(direction).y)->isEmpty()) {
            placer.moveFrom(room, this, this->getLocation(),
                            {this->getXY().first + dir.getDir(direction).x,
                             this->getXY().second + dir.getDir(direction).y});
            room->getPlayerSearchOverlay()->updateOverlay(direction);
        } else {
            interact(room->getTile(this->getXY().first + dir.getDir(direction).x,
                                        this->getXY().second + dir.getDir(direction).y)->getEnitity());
            tmp = room->getTile(this->getXY().first + dir.getDir(direction).x,
                          this->getXY().second + dir.getDir(direction).y)->getEnitity();
            i_tmp = dynamic_cast<Item *>(tmp);
            if (i_tmp && i_tmp->isTaken()) placer.deleteFromRoom(room, i_tmp, {this->getXY().first + dir.getDir(direction).x,
                                                                               this->getXY().second + dir.getDir(direction).y});
        }
    else return;
}

void Player::attack(IEntity *target) {
    if (target) {
        auto enemy = dynamic_cast<Actor *>(target);
        if (this->weapon)
            enemy->getDMG(this->weapon->getATK() + this->baseATK);
        else enemy->getDMG(this->baseATK);
    } else return;
}

void Player::setWeapon(IWeapon *new_weapon) {
    this->weapon = new_weapon;
    /*if (this->weapon) {
        this->baseATK += this->weapon->getATK();
        this->baseRNGE = this->weapon->getRNGE();
    }*/
}

void Player::interact(IEntity *target) {
    auto enemy = dynamic_cast<Actor*>(target);
    if (enemy) {
        attack(enemy);
        return;
    } else {
        target->interact(this);
        dynamic_cast<Item *>(target)->setTaken(true);
    }
}

/*void Player::discard() {

}*/

void Player::setPotion(IPotion *potion) {
    this->potion = potion;
}
