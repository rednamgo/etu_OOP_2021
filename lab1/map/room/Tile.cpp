//
// Created by red on 05.12.2021.
//

#include "Tile.h"

Tile::Tile(int tileType, bool isWalkable, bool empty): tileType(tileType), isWalkable(isWalkable), empty(empty) {
    this->entity = NULL;
}

Tile::Tile() {
    this->entity = NULL;
}

Tile::~Tile() = default;

void Tile::setEntity(IEntity *e) {
    this->entity = e;
    if (entity) {
        this->empty = false;
    } else this->empty = true;

}

void Tile::setWalk(bool canWalk) {
    this->isWalkable = canWalk;
}

void Tile::setType(int type) {
    this->tileType = type;
    this->empty = true;
    if (type == FLOOR || type == ENTRANCE) this->isWalkable = true;
        else if (type == WALL || type == EXIT) this->isWalkable = false;
}

bool Tile::canWalk() {
    return this->isWalkable;
}

bool Tile::isEmpty() {
    return this->empty;
}

int Tile::getType() {
    return this->tileType;
}

void Tile::removeEntity() {
    //delete this->entity;
    setType(FLOOR);
    this->entity = nullptr;
}

/*
Tile::Tile(const Tile &other) {
    this->isWalkable = other.isWalkable;
    this->empty = other.empty;
    //this->entity = other.entity;
    this->tileType = other.tileType;
}

Tile &Tile::operator=(const Tile &other) {
    if (&other == this) return *this;
    //delete entity;

    //this->entity = other.entity;
    this->isWalkable = other.isWalkable;
    this->empty = other.empty;
    this->tileType = other.tileType;

    return *this;
}

Tile::Tile(Tile &&other) noexcept : isWalkable{other.isWalkable}, empty {other.empty}, tileType {other.tileType} { //entity{other.entity}
    //this->entity = other.entity;
    this->isWalkable = other.isWalkable;
    this->empty = other.empty;
    this->tileType = other.tileType;
}

Tile &Tile::operator=(Tile &&other) noexcept {
    if (&other == this) return *this;
    //this->entity = other.entity;
    this->isWalkable = other.isWalkable;
    this->empty = other.empty;
    this->tileType = other.tileType;
    return *this;
}
*/