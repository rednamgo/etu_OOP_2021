//
// Created by red on 18.12.2021.
//
#include "../../../creatures/enemies/IEnemy.h"
#include "MovementBehavior.h"
#include "AI.h"

void Flee:: move (Room *room, IEnemy &enemy) {
    Placement placer(&enemy);
    gridLocation tmp = enemy.getLocation();
    gridLocation shortestPath = room->getPlayerSearchOverlay()->getShortestPath(tmp);
    std::map<gridLocation, int> *layer = room->getPlayerSearchOverlay()->getLayer();
    while (enemy.getRNGE() < room->getPlayerSearchOverlay()->getLayer()->operator[](enemy.getLocation())) { //->getOverlay()[enemy.getXY().first][enemy.getXY().second]
        tmp = enemy.getLocation();
        placer.place(room, &enemy, shortestPath);
        shortestPath = room->getPlayerSearchOverlay()->getShortestPath(tmp); //get next tile to move to
    }
}

void ConfusedWalk::move (Room *room, IEnemy &enemy) {
    Placement placer(&enemy);
    randNum rng;
    Direction dir;
    std::map<gridLocation, int> *layer = room->getPlayerSearchOverlay()->getLayer();
    while (room->getPlayerSearchOverlay()->getLayer()->operator[](enemy.getLocation()) > 7) //Enemy sees 7 tiles ahead
        placer.place(room, &enemy, dir.getDir(rng.getRand(1, 4)));
    enemy.getAI()->setPlayer(room->getPlayer()); //once we exit loop <-> see player -> set player ptr
}

void CloseIn::move(Room *room, IEnemy &enemy) {
    Placement placer(&enemy);
    gridLocation tmp = enemy.getLocation();
    gridLocation shortestPath = room->getPlayerSearchOverlay()->getShortestPath(tmp);
    std::map<gridLocation, int> *layer = room->getPlayerSearchOverlay()->getLayer();
    while (enemy.getRNGE() < room->getPlayerSearchOverlay()->getLayer()->operator[](enemy.getLocation())) {
        tmp = enemy.getLocation();
        placer.place(room, &enemy, shortestPath);
        shortestPath = room->getPlayerSearchOverlay()->getShortestPath(tmp); //get next tile to move to
    }
}
