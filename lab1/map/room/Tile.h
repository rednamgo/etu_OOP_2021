//
// Created by red on 05.12.2021.
//

#ifndef REWORKED_TILE_H
#define REWORKED_TILE_H
#include "../../../lab2/IEntity.h"
#include <iostream>

enum TileType {
    FLOOR = '.',
    WALL = '#',
    ENTRANCE = 'E',
    EXIT = 'O'
};

class Tile {
public:
    Tile();
    Tile(int tileType, bool isWalkable, bool empty);
    ~Tile();
    //Tile (const Tile& other); //construct & copy operator
    //Tile& operator = (const Tile& other);
    //Tile (Tile&& other) noexcept;//construct & move operator
    //Tile& operator = (Tile&& other) noexcept;
    void setEntity(IEntity *e);
    void removeEntity();
    IEntity *getEnitity() {return this->entity;}
    void setType(int type);
    void setWalk(bool);
    bool canWalk();
    int getType();
    bool isEmpty();
private:
    IEntity *entity;
    int tileType{};
    bool isWalkable{};
    bool empty{};
};


#endif //REWORKED_TILE_H
