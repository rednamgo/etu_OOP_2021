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
    Player(): Actor(baseHP = 200, baseMP = 50, baseRNGE = 1, baseATK = 10, HPcap = 200, MPcap = 50){};
    ~Player() = default;
    void interact(IEntity *);
    void die(Room *room);
    void move (int direction, Room *room);
    void attack (IEntity *target);
    //void lvlUp() {this->lvl++;} //active when complete lvl
    void setWeapon(IWeapon *);
    IWeapon* getWeapon (){return this->weapon;}
    void setPotion(IPotion *);
    //void discard(); ///discard thing on the cell player is on; -> WIP
    int getType() override {return 0;}
    int getATK() override {if (weapon) return weapon->getATK(); else return this->baseATK;}
    std::string getName() override {return "Player";}

private:
    int baseHP = 200, baseMP = 50, baseRNGE = 1, baseATK = 10; //initial values
    int lvl = 1;
    int HPcap = 200*lvl, MPcap = 50*lvl; //max hp and mp
    IWeapon *weapon = nullptr;
    IPotion *potion = nullptr;
};


#endif //REWORKED_PLAYER_H
