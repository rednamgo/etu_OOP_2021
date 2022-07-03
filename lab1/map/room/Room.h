//
// Created by red on 05.12.2021.
//

#ifndef REWORKED_ROOM_H
#define REWORKED_ROOM_H
#include "Tile.h"
//#include "../../../lab2/tools/Direction.h"
#include "../../../lab2/tools/overlays/PlayerSearchOverlay.h"

class Player;
class Room {
public:
    Room(): height(0), width(0), array(nullptr), killCnt(0) {};
    ~Room();
    Room(int num, int height, int width, std::pair<int, int> entry, std::pair<int, int> exit);
    Room (const Room& other); //construct & copy operator
    Room& operator = (const Room& other);
    Room (Room&& other) noexcept;//construct & move operator
    Room& operator = (Room&& other) noexcept;

    std::pair<int, int> getHeightWidth();
    void setArray(Tile **tmp) {this->array = tmp;}
    Tile **getArray() {return this->array;}
    Tile *getTile(int x, int y) {return &this->array[x][y];}
    std::pair<int, int> getEntry() {return this->entry;}
    std::pair<int, int> getExit() {return this->exit;}
    int getNum() {return this->num;}
    void setWidth(int val) {this->width = val;}
    void setHeight(int val) {this->height = val;}
    void setEntry(int x, int y) {this->entry.first = x; this->entry.second = y;}
    void setExit(int x, int y) {this->exit.first = x; this->exit.second = y;}
    //void setEntity(IEntity *entity, int x, int y);
    void setPlayer(Player *p) {this->player = p;}
    Player *getPlayer() {return this->player;}
    void addEntity(IEntity *entity) {this->entities.push_back(entity);}
    std::vector<IEntity*> getEntities() {return this->entities;}
    void setOverlay();
    PlayerSearchOverlay *getPlayerSearchOverlay() {return &this->overlay[0];}
    PlayerSearchOverlay *getFleeOverlay() {return &this->overlay[1];}
    void setEnemyCnt(int cnt) {this->enemyCnt = cnt;}
    int getEnemyCnt() {return this->enemyCnt;}
    void setKillCnt() {this->killCnt++;}
    int getKillCnt() {return this->killCnt;}

    //Overlay *getOverlay() {return this->overlay;}
private:
    int height, width;
    Tile **array;
    std::pair<int, int> entry, exit;
    int enemyCnt;
    int killCnt;
    int num;
    PlayerSearchOverlay *overlay;
    std::vector<IEntity*> entities;
    Player *player;
};


#endif //REWORKED_ROOM_H
