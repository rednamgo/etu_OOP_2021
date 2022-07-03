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
    if (enemy.getRNGE() < layer->operator[](enemy.getLocation())) { //->getOverlay()[enemy.getXY().first][enemy.getXY().second]
        tmp = enemy.getLocation();
        //placer.place(room, &enemy, shortestPath);
        placer.moveFrom(room, &enemy, enemy.getLocation(), shortestPath);
        shortestPath = room->getPlayerSearchOverlay()->getShortestPath(tmp); //get next tile to move to
    } else return;
}

void ConfusedWalk::move (Room *room, IEnemy &enemy) {
    Placement placer(&enemy);
    randNum rng;
    Direction dir;
    gridLocation r = dir.getDir(rng.getRand(1, 4));
    std::map<gridLocation, int> *layer = room->getPlayerSearchOverlay()->getLayer();
    if (layer->operator[](enemy.getLocation()) > 7) { //Enemy sees 7 tiles ahead
        r = {enemy.getLocation().x + r.x, enemy.getLocation().y + r.y};
        placer.moveFrom(room, &enemy, enemy.getLocation(), r);
    }
    else enemy.getAI()->setPlayer(room->getPlayer()); //
    /*if (room->getPlayerSearchOverlay()->getLayer()->operator[](enemy.getLocation()) > 7) //Enemy sees 7 tiles ahead
        placer.place(room, &enemy, dir.getDir(rng.getRand(1, 4)));
    else enemy.getAI()->setPlayer(room->getPlayer()); //once we exit loop <-> see player -> set player ptr*/
}

void CloseIn::move(Room *room, IEnemy &enemy) {
    Placement placer(&enemy);
    gridLocation tmp = enemy.getLocation();
    gridLocation shortestPath = room->getPlayerSearchOverlay()->getShortestPath(tmp);
    std::map<gridLocation, int> *layer = room->getPlayerSearchOverlay()->getLayer();
    if (enemy.getRNGE() < room->getPlayerSearchOverlay()->getLayer()->operator[](enemy.getLocation())) {
        tmp = enemy.getLocation();
        placer.moveFrom(room, &enemy, enemy.getLocation(), shortestPath);
        //placer.place(room, &enemy, shortestPath);
        //shortestPath = room->getPlayerSearchOverlay()->getShortestPath(tmp); //get next tile to move to
    } else return; //enemy.getAtkBehavior()->attack(enemy, *room->getPlayer());
}
