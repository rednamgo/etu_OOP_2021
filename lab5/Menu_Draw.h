//
// Created by red on 12.05.22.
//

#ifndef REWORKED_MENU_DRAW_H
#define REWORKED_MENU_DRAW_H
#include "../lab1/map/room/Room.h"
#include "../lab2/creatures/enemies/IEnemy.h"

class MenuDraw {
public:
    MenuDraw() = default;
    ~MenuDraw() = default;
    void print(Room *room) {
        print_player_info(room);
        print_enemy_info(room);
    }
    void print_player_info(Room *room) {
        std::cout << "--------------------------" << std::endl;
        std::cout << "  Player HP: " << room->getPlayer()->getHP() << "/" <<  room->getPlayer()->getMaxHP() << "\n\tATK: " << room->getPlayer()->getATK() <<
        "(+";
        if (room->getPlayer()->getWeapon()) {
            std::cout << room->getPlayer()->getWeapon()->getATK() << " from " << room->getPlayer()->getWeapon()->getName() << ")" << std::endl << std::endl;
        } else std::cout << "0)" << std::endl << std::endl;
    }
    
    void print_enemy_info(Room *room) {
        std::cout << "  ENEMIES LEFT: " << std::endl;
        for (int i = 0; i < room->getEnemyCnt(); i++) {
            if (!dynamic_cast<IEnemy *>(room->getEntities()[i])->isDead()) {
                std::cout << "\t" << room->getEntities()[i]->getName() << " HP: " <<
                          dynamic_cast<IEnemy *>(room->getEntities()[i])->getHP() << "/" << dynamic_cast<IEnemy *>(room->getEntities()[i])->getMaxHP() << std::endl;
            }
        }
        std::cout << std::endl;
    }
};


#endif //REWORKED_MENU_DRAW_H
