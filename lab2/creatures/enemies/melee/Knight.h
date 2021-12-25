//
// Created by red on 08.12.2021.
//

#ifndef REWORKED_KNIGHT_H
#define REWORKED_KNIGHT_H

#include "../../Actor.h"
#include "../IEnemy.h"
#include "../AI/AI.h"

class Knight: public IEnemy {
public:
    Knight(): Actor(baseHP, baseMP, baseRNGE, baseATK, HPCAP, MPCAP) {this->ai = new AI;}
    ~Knight() = default;
    void act(Player &, Room *room);;
    void setMoveBehavior(MovementBehavior *m) {this->movementBehavior = m;}
    void setAtkBehavior(AttackBehavior *a) {this->attackBehavior = a;}
    void setDeathBehavior(DeathBehavior *d) {this->deathBehavior = d;}
    MovementBehavior *getMoveBehavior() {return this->movementBehavior;}
    AttackBehavior *getAtkBehavior() {return this->attackBehavior;}
    DeathBehavior *getDeathBehavior() {return this->deathBehavior;}
    int getType() override {return 4;}
    int getRNGE() override {return this->baseRNGE;}
    int getATK(){return this->baseATK;}
    AI* getAI() {return this->ai;}

protected:
    MovementBehavior *movementBehavior;
    AttackBehavior *attackBehavior;
    DeathBehavior *deathBehavior;

    int HPCAP = 100*lvl, MPCAP = 20*lvl;
    int baseHP = 100, baseMP = 10, baseATK = 10, baseRNGE = 11;
    int lvl = 1;
    AI *ai;
};

#endif //REWORKED_KNIGHT_H
