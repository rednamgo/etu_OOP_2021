//
// Created by red on 08.12.2021.
//

#ifndef REWORKED_DEMON_H
#define REWORKED_DEMON_H
#include "../IEnemy.h"
#include "../AI/AI.h"

class Demon: public IEnemy{
public:
    Demon(): Actor(baseHP, baseMP, baseRNGE, baseATK, HPCAP, MPCAP) {this->ai = new AI;}
    ~Demon() = default;
    void act(Player &, Room *room);
    void setMoveBehavior(MovementBehavior *m) {this->movementBehavior = m;}
    void setAtkBehavior(AttackBehavior *a) {this->attackBehavior = a;}
    void setDeathBehavior(DeathBehavior *d) {this->deathBehavior = d;}
    MovementBehavior *getMoveBehavior() {return this->movementBehavior;}
    AttackBehavior *getAtkBehavior() {return this->attackBehavior;}
    DeathBehavior *getDeathBehavior() {return this->deathBehavior;}
    int getType() override {return 5;}
    int getRNGE() override {return this->baseRNGE;}
    int getATK(){return this->baseATK;}
    AI* getAI() {return this->ai;}
protected:
    MovementBehavior *movementBehavior;
    AttackBehavior *attackBehavior;
    DeathBehavior *deathBehavior;

    int HPCAP = 50*lvl, MPCAP = 150*lvl;
    int baseHP = 50, baseMP = 100, baseRNGE = 2, baseATK = 10;
    int lvl = 1;
    AI *ai;
};


#endif //REWORKED_DEMON_H
