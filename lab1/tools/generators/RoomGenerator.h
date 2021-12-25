//
// Created by red on 05.12.2021.
//

#ifndef REWORKED_ROOMGENERATOR_H
#define REWORKED_ROOMGENERATOR_H
#include "IGenerate.h"
#include "randNum.h"
#include "../txtMng.h"
#include "../../../lab2/tools/Direction.h"
//#include "../../map/room/Room.h"

#define MAX_SIZE 15
#define MIN_SIZE 10

class RoomGenerator: IGenerate {
public:
    RoomGenerator(Room *room, bool isFromFile = false) : room(room), isFromFile(isFromFile) {};
    ~RoomGenerator() = default;
    void generate() override; //generate the room itself
    void createEntry(); //generate Entrance
    void setWall(std::pair<int, int> xy);
    void setEntry(std::pair<int, int> xy);
    void setExit(std::pair<int, int> xy); //set Exit
    void setFloor(std::pair<int, int> xy);
    void setRoom(Room *room) {this->room = room;}
    void readFromFile(int num); //read room from file
    void createTunnels(); //create walkable tiles in the room of walls
    void saveIntoFile(std::string name);

private:
    Room *room;
    bool isFromFile;
};


#endif //REWORKED_ROOMGENERATOR_H
