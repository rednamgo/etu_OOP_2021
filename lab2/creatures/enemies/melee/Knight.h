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
    Knight(): Actor(baseHP = 50, baseMP = 10, baseRNGE = 1, baseATK = 10, HPCAP = 50, MPCAP = 20) {
        this->ai = new AI;
        this->dead = false;
    }
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
    int getATK() override{return this->baseATK;}
    AI* getAI() override {return this->ai;}
    std::string getName() override {return "Knight";}
    void setDead(bool d) {this->dead = d;}
    bool isDead() {return this->dead;}

protected:
    MovementBehavior *movementBehavior;
    AttackBehavior *attackBehavior;
    DeathBehavior *deathBehavior;

    bool dead;

    int lvl = 1;
    int HPCAP = 50*lvl, MPCAP = 20*lvl;
    int baseHP = 50, baseMP = 10, baseATK = 10, baseRNGE = 1;

    AI *ai;
};

#endif //REWORKED_KNIGHT_H
