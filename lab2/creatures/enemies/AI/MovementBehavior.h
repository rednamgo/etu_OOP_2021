//
// Created by red on 17.12.2021.
//

#ifndef REWORKED_MOVEMENTBEHAVIOR_H
#define REWORKED_MOVEMENTBEHAVIOR_H
#include "../../../../lab1/map/room/Room.h"
#include "../../../../lab1/tools/generators/randNum.h"
#include "../../../tools/overlays/Overlay.h"
#include "../../../tools/Placement.h"
#include <map>
class IEnemy;

class MovementBehavior {
public:
    virtual void move (Room *room, IEnemy &enemy) = 0;
};

class Flee: public MovementBehavior {
public:
    Flee() = default;
    ~Flee() = default;
    void move (Room *room, IEnemy &enemy) override;
};

class ConfusedWalk: public MovementBehavior {
public:
    ConfusedWalk() = default;
    ~ConfusedWalk() = default;
    void move (Room *room, IEnemy &enemy) override;
};

class CloseIn: public MovementBehavior {
public:
    CloseIn() = default;
    ~CloseIn() = default;
    void move (Room *room, IEnemy &enemy) override;
};

#endif //REWORKED_MOVEMENTBEHAVIOR_H
