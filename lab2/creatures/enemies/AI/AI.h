//
// Created by red on 08.12.2021.
//

#ifndef REWORKED_AI_H
#define REWORKED_AI_H
#include "../../../../lab1/map/room/Room.h"
#include "../../../../lab1/tools/generators/randNum.h"
#include "../AI/MovementBehavior.h"
#include "../AI/AttackBehavior.h"
#include "../AI/DeathBehavior.h"

class ConfusedWalk;
class CloseIn;

class IEnemy;

class AI {
public:
    AI() {this->player = nullptr;}
    void setPlayer(Player *player){this->player = player;}
    void decisionTree(Room *room, IEnemy &enemy);
private:
    Player *player;
    MovementBehavior *confused = new ConfusedWalk;
    MovementBehavior *flee = new Flee;
    MovementBehavior *closeIn = new CloseIn;
    AttackBehavior *attack = new AttackBehavior;
    DeathBehavior *death = new DeathBehavior;
};

#endif //REWORKED_AI_H
