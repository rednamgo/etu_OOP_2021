//
// Created by red on 07.12.2021.
//

#ifndef REWORKED_PLAYER_H
#define REWORKED_PLAYER_H
#include "../Actor.h"
#include "../../IEntity.h"
#include "../../items/weapons/IWeapon.h"
#include "../../items/potions/IPotion.h"
#include "../../tools/Placement.h"
//#include "../../tools/Direction.h"

class Player: public Actor {
public:
    Player(): Actor(baseHP, baseMP, baseRNGE, baseATK, HPcap, MPcap){};
    ~Player() = default;
    void interact(IEntity *);
    void die(Room *room);
    void move (int direction, Room *room);
    void attack (IEntity *target);
    //void lvlUp() {this->lvl++;} //active when complete lvl
    void setWeapon(IWeapon *);
    void setPotion(IPotion *);
    //void discard(); ///discard thing on the cell player is on; -> WIP
    int getType() override {return 0;}

private:
    int baseHP = 50, baseMP = 50, baseRNGE = 1, baseATK = 5; //initial values
    int HPcap = 50*lvl, MPcap = 50*lvl; //max hp and mp
    int lvl = 1;
    IWeapon *weapon = nullptr;
    IPotion *potion = nullptr;
};


#endif //REWORKED_PLAYER_H
