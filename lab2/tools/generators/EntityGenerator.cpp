//
// Created by red on 12.12.2021.
//

#include "EntityGenerator.h"
//#include "../../../lab1/map/room/Room.cpp"

void EntityGenerator::generate() {
    generatePlayer();
    setFreeTiles();
    setEnemyNum();
    spawn(ENEMY_DIST);
    this->room->setEnemyCnt(this->entityNum);
    setItemNum();
    spawn(ITEM_DIST);
}

void EntityGenerator::setEnemyNum() {
    randNum gen;
    this->entityNum = gen.getRand(1, this->room->getHeightWidth().second / 3); //each 3 tiles +1 monster can be spawned
}

void EntityGenerator::setItemNum() {
    randNum gen;
    this->entityNum = gen.getRand(0, this->room->getHeightWidth().second / 10); //each 10 tiles +1 item can be spawned
}

void EntityGenerator::setFreeTiles() { //MIN_SIZE of the room = 10, spawn area -2
    for (int i = 2; i < this->room->getHeightWidth().first - 2; i++) {
        for (int j = 2; j < this->room->getHeightWidth().second - 2; j++) {
            if (this->room->getArray()[i][j].getType() == FLOOR)
                this->freeTiles.push_back({i, j});
        }
    }
}

void EntityGenerator::generateEnemies(gridLocation &spawnXY, int &minTile, int index) {
    this->room->getArray()[spawnXY.x][spawnXY.y].setEntity(createEnemy(index));
    auto *tmp = dynamic_cast<Actor *>(this->room->getArray()[spawnXY.x][spawnXY.y].getEnitity());
    if (tmp) tmp->setXY(spawnXY.x, spawnXY.y);
    this->room->addEntity(this->room->getArray()[spawnXY.x][spawnXY.y].getEnitity()); //get entity ptr directly to avoid slicing
}

void EntityGenerator::generateItems(gridLocation &spawnXY, int &minTile, int index) {
    this->room->getArray()[spawnXY.x][spawnXY.y].setEntity(createItem(index));
    this->room->addEntity(this->room->getArray()[spawnXY.x][spawnXY.y].getEnitity());
}

IEnemy *EntityGenerator::createEnemy(int type) {
    switch (type) {
        case KNIGHT:
            return new Knight();
        case DEMON:
            return new Demon();
        case MAGE:
            return new Mage();
    }
    return nullptr;
}

Item *EntityGenerator::createItem(int type) {
    switch (type) {
        case HPOTION:
            return new HPotion();
        case POISON:
            return new Poison();
        case DAGGER:
            return new Dagger();
    }
    return nullptr;
}

void EntityGenerator::spawn(int type) {
    randNum gen;
    int index = 0;
    int minTile = 0;
    gridLocation spawnXY = {0, 0};
    for (int i = 0; i < this->entityNum; i++) {
        index = gen.getRand(0, this->freeTiles.size() - 1);//get rand free tile
        spawnXY = {this->freeTiles[index].x, this->freeTiles[index].y}; //set this tile for spawn
        this->freeTiles.erase(std::next(freeTiles.begin(), index)); //delete this tile from free tiles
        index = gen.getRand(1, 3);//get rand entity type
        if (this->room->getArray()[spawnXY.x][spawnXY.y].isEmpty()) {
            if (type == ENEMY_DIST) generateEnemies(spawnXY, minTile, index);
            else generateItems(spawnXY, minTile, index);
        } else {
            i--;
            continue;
        }
    }
}

EntityGenerator::~EntityGenerator() {
    delete room;
    freeTiles.clear();
}

void EntityGenerator::generatePlayer() {
    auto *player = new Player;
    player->setXY(this->room->getEntry().first, this->room->getEntry().second);
    this->room->getArray()[this->room->getEntry().first][this->room->getEntry().second].setEntity(player);
    this->room->setPlayer(player);
}
