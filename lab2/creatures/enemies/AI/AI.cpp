//
// Created by red on 18.12.2021.
//

#include "AI.h"
//#include "../AI/MovementBehavior.h"
#include "../../../creatures/enemies/IEnemy.h"

void AI::decisionTree(Room *room, IEnemy &enemy) {//0 HP -> die; no player -> walk; player and low HP (or player too close) -> flee; else get close and atk
    //std::map<gridLocation, int> *layer = room->getPlayerSearchOverlay()->getLayer();
        if (enemy.getHP() <= 0) {
            enemy.setDeathBehavior(death);
            enemy.getDeathBehavior()->die(room, &enemy);
        }
        if (this->player == nullptr) {
                enemy.setMoveBehavior(this->confused); //if not in sight range -> walk randomly
                enemy.getMoveBehavior()->move(room, enemy);
            }
        else if (this->player) {
                if (enemy.getHP() > enemy.getMaxHP() / 3 &&
                        room->getPlayerSearchOverlay()->getLayer()->operator[](enemy.getLocation()) > enemy.getRNGE() / 2) {
                    if (room->getPlayerSearchOverlay()->getLayer()->operator[](enemy.getLocation()) > enemy.getRNGE()) {
                        enemy.setMoveBehavior(this->closeIn);  //close in to the player
                        enemy.getMoveBehavior()->move(room, enemy);
                    }
                    else enemy.getAtkBehavior()->attack(enemy, *room->getPlayer());
                } else if (enemy.getType() == 6) {
                    enemy.setMoveBehavior(flee);
                    enemy.getMoveBehavior()->move(room, enemy); //if mage && player in sight && injured -> flee
                }
            }
}


