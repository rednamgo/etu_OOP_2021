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
    Direction dir;
    Placement placer{};
    if (room->getTile(this->getXY().first + dir.getDir(direction).x, this->getXY().second + dir.getDir(direction).y)->canWalk())
        placer.moveFrom(room, this, this->getLocation(),
                    {this->getXY().first + dir.getDir(direction).x, this->getXY().second + dir.getDir(direction).y});
    else return;
}

void Player::attack(IEntity *target) {
    auto enemy = dynamic_cast<Actor*>(target);
    if (this->weapon)
        enemy->getDMG(this->weapon->getATK());
    else enemy->getDMG(this->baseATK);
}

void Player::setWeapon(IWeapon *new_weapon) {
    this->weapon = new_weapon;
}

void Player::interact(IEntity *target) {
    auto enemy = dynamic_cast<Actor*>(target);
    if (enemy) {
        attack(enemy);
        return;
    }
    target->interact(this);
}

/*void Player::discard() {

}*/

void Player::setPotion(IPotion *potion) {
    this->potion = potion;
}
