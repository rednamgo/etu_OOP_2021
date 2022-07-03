//
// Created by red on 08.12.2021.
//

#ifndef REWORKED_DEMON_H
#define REWORKED_DEMON_H
#include "../IEnemy.h"
#include "../AI/AI.h"

class Demon: public IEnemy{
public:
    Demon(): Actor(baseHP = 25, baseMP = 100, baseRNGE = 1, baseATK = 5, HPCAP = 25, MPCAP = 150) {
        this->ai = new AI;
        this->dead = false;
    }
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
    int getATK() override{return this->baseATK;}
    AI* getAI() {return this->ai;}
    std::string getName() override {return "Demon";}

    void setDead(bool d) {this->dead = d;}
    bool isDead() {return this->dead;}

protected:
    bool dead;
    MovementBehavior *movementBehavior;
    AttackBehavior *attackBehavior;
    DeathBehavior *deathBehavior;
    int lvl = 1;
    int HPCAP = 25*lvl, MPCAP = 150*lvl;
    int baseHP = 25, baseMP = 100, baseRNGE = 1, baseATK = 5;

    AI *ai;
};


#endif //REWORKED_DEMON_H
