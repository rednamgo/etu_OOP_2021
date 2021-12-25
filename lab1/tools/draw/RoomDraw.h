//
// Created by red on 05.12.2021.
//

#ifndef REWORKED_ROOMDRAW_H
#define REWORKED_ROOMDRAW_H
#include "IDraw.h"
#include "../../map/room/Room.h"
#include "../../../lab2//creatures/Actor.h"
#include "../../../lab2/items/Item.h"
#include <iostream>

enum drawSymbols {
    FLOOR_SYM = '.',
    WALL_SYM = '#',
    ENTRY_SYM = 'E',
    EXIT_SYM = 'O',
    CHAR_SYM = '@',
    ENEMY_SYM = 'J',
    KNIGHT_SYM = 'K',
    MAGE_SYM = 'M',
    DEMON_SYM = 'D',
    ITEM_SYM = 'I',
    HPOTION_SYM = 'H',
    POISON_SYM = 'P',
    WEAPON_SYM = 'W',
    UNKNOWN = '?'
};

class RoomDraw: IDraw {
public:
    virtual void draw(Room *room) {
        int height = room->getHeightWidth().first, width = room->getHeightWidth().second;
        Tile **arr = room->getArray();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (arr[i][j].isEmpty()) {
                    setChar(arr[i][j].getType());
                } else findEntityType(arr[i][j].getEnitity());
                std::cout << symbol << ' ';
            }
            std::cout << std::endl;
        }
    };
    virtual void setChar(char newchar) {
        this->symbol = newchar;
    }
    void findEntityType(IEntity *entity);
private:
    char symbol;
};

void RoomDraw::findEntityType(IEntity *entity) {
    int type = entity->getType();
    if (type == 0) setChar(CHAR_SYM);
    else if (type == 1) setChar(WEAPON_SYM);
        else if (type == 2) setChar(POISON_SYM);
            else if (type == 3) setChar(HPOTION_SYM);
    else if (type == 4) setChar(KNIGHT_SYM);
        else if (type == 5) setChar(DEMON_SYM);
        else if (type == 6) setChar(MAGE_SYM);
    else setChar(UNKNOWN);
}

#endif //REWORKED_ROOMDRAW_H
