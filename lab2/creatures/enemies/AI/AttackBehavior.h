//
// Created by red on 18.12.2021.
//

#ifndef REWORKED_ATTACKBEHAVIOR_H
#define REWORKED_ATTACKBEHAVIOR_H
#include "../../player/Player.h"
#include "../IEnemy.h"
//class IEnemy;
//class Player;

class AttackBehavior {
public:
    void attack(IEnemy& enemy, Player &player) {
        player.getDMG(enemy.getATK());
        if (enemy.getType() == 5 && (enemy.getMaxHP() - enemy.getHP()) > 1)   //if its demon - it heals with each attack
            enemy.heal(1);
    }
};


#endif //REWORKED_ATTACKBEHAVIOR_H
