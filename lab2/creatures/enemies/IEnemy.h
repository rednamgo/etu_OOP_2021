//
// Created by red on 07.12.2021.
//

#ifndef REWORKED_IENEMY_H
#define REWORKED_IENEMY_H
#include "../Actor.h"
#include "../player/Player.h"
class MovementBehavior;
class AttackBehavior;
class DeathBehavior;
class AI;
class Room;

class IEnemy: virtual public Actor {
public:
    //virtual void die() = 0;
    //virtual void attack(Player &) = 0;
    virtual void act(Player &, Room *room) = 0;
    //virtual void move(int direction) = 0;
    virtual void setMoveBehavior(MovementBehavior *m) = 0;
    virtual void setAtkBehavior(AttackBehavior *a) = 0;
    virtual void setDeathBehavior(DeathBehavior *d) = 0;
    virtual MovementBehavior *getMoveBehavior() = 0;
    virtual AttackBehavior *getAtkBehavior() = 0;
    virtual DeathBehavior *getDeathBehavior() = 0;
    virtual std::string getName() = 0;
    virtual int getType() = 0;
    virtual int getRNGE() = 0;
    virtual int getATK() = 0;
    virtual AI* getAI() = 0;
    virtual void setDead(bool d) = 0;
    virtual bool isDead() = 0;
};


#endif //REWORKED_IENEMY_H
