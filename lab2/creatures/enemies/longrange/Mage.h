//
// Created by red on 08.12.2021.
//

#ifndef REWORKED_MAGE_H
#define REWORKED_MAGE_H
#include "../IEnemy.h"
#include "../AI/AI.h"

class Mage: public IEnemy{
public:
    Mage(): Actor(baseHP, baseMP, baseRNGE, baseATK, HPCAP, MPCAP) {this->ai = new AI;}
    ~Mage() = default;
    void act(Player &, Room *room);
    void setMoveBehavior(MovementBehavior *m) {this->movementBehavior = m;}
    void setAtkBehavior(AttackBehavior *a) {this->attackBehavior = a;}
    void setDeathBehavior(DeathBehavior *d) {this->deathBehavior = d;}
    MovementBehavior *getMoveBehavior() {return this->movementBehavior;}
    AttackBehavior *getAtkBehavior() {return this->attackBehavior;}
    DeathBehavior *getDeathBehavior() {return this->deathBehavior;}
    //void heal(Actor &target);
    //void interact(IEntity*) override {};
    int getType() override {return 6;}
    int getRNGE() {return this->baseRNGE;}
    int getATK() {return this->baseATK;}
    AI* getAI() {return this->ai;}

protected:
    MovementBehavior *movementBehavior;
    AttackBehavior *attackBehavior;
    DeathBehavior *deathBehavior;

    int HPCAP = 50*lvl, MPCAP = 100*lvl;
    int baseATK = 1, baseHP = 20, baseMP = 100, baseRNGE = 5;
    int lvl = 1;
    AI *ai = new AI;

};


#endif //REWORKED_MAGE_H
