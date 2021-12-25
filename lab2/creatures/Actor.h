//
// Created by red on 07.12.2021.
//

#ifndef REWORKED_ACTOR_H
#define REWORKED_ACTOR_H
#include "../IEntity.h"
//#include "../items/Item.h"
#include <iostream>
#include "../tools/Direction.h"

enum actorTypes { ///maybe delete
    PLAYER = 1,
    ENEMY = 2,
    OTHER = 3
};

class Actor: public IEntity {
public:
    Actor(int HP, int MP, int RNGE, int ATK, int HPcap, int MPcap): HP(HP), MP(MP), RNGE(RNGE), ATK(ATK),
        HPcap(HPcap), MPcap(MPcap) {};
    //virtual void interact(IEntity*) = 0; //different implementation for enemies and player
    //virtual void move(int direction) = 0; //different implementation for enemies and player
    void getDMG(int dmg) {this->HP -= dmg;}
    void heal (int hp) {this->HP += hp;}
    //virtual void die() = 0; //different implementation for enemies and player
    virtual int getType() = 0;
    int getHP() {return this->HP;}
    int getMaxHP() {return this->HPcap;}
    void setXY(int x, int y) {this->x = x; this->y = y;}
    std::pair<int, int> getXY() {std::pair<int, int> xy = {this->x, this->y}; return xy;}
    gridLocation getLocation() {xy = {x, y}; return xy;}

private:
    int HP, MP, RNGE, ATK;
    int HPcap, MPcap;
    int x, y;
    gridLocation xy;
};


#endif //REWORKED_ACTOR_H
