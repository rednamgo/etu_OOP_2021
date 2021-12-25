//
// Created by red on 06.12.2021.
//

#ifndef REWORKED_MAPGENERATOR_H
#define REWORKED_MAPGENERATOR_H
#include "IGenerate.h"
#include "../../map/Map.h"
#include "RoomGenerator.h"
#include "/home/red/Uni/OOP/reworked/lab1/tools/savers/SaveRoom.h"

class MapGenerator: IGenerate {
public:
    MapGenerator() = default;
    MapGenerator(int n = 5, bool fromFile = false): cnt(n), isFromFile(fromFile) {};
    ~MapGenerator() {delete map;}
    void generate() override;
    void rngMap();
    void readFromFile();
    void saveInFile(std::string directory);
    void setMap(Map *mapprt) {mapprt = this->map;}

private:
    Map *map;
    bool isFromFile;
    int cnt;
};


#endif //REWORKED_MAPGENERATOR_H
