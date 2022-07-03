//
// Created by red on 08.12.2021.
//

#ifndef REWORKED_MAGE_H
#define REWORKED_MAGE_H
#include "../IEnemy.h"
#include "../AI/AI.h"

class Mage: public IEnemy{
public:
    Mage(): Actor(baseHP = 20, baseMP = 100, baseRNGE = 5, baseATK = 1, HPCAP = 20, MPCAP = 100) {
        this->ai = new AI;
        this->dead = false;
    }
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
    int getRNGE() override {return this->baseRNGE;}
    int getATK() override {return this->baseATK;}
    AI* getAI() override {return this->ai;}
    std::string getName() override {return "Mage";}
    void setDead(bool d) {this->dead = d;}
    bool isDead() {return this->dead;}

protected:
    bool dead;
    MovementBehavior *movementBehavior;
    AttackBehavior *attackBehavior;
    DeathBehavior *deathBehavior;

    int lvl = 1;
    int HPCAP = 20*lvl, MPCAP = 100*lvl;
    int baseATK = 1, baseHP = 20, baseMP = 100, baseRNGE = 5;

    AI *ai = new AI;

};


#endif //REWORKED_MAGE_H
