//
// Created by red on 05.11.2021.
//

#ifndef LAB1_TXTMNG_H
#define LAB1_TXTMNG_H

#include <iostream>
#include <fstream>
#include <vector>

class txtMng {
public:
    explicit txtMng(std::string filename = "", std::string type = "");
    ~txtMng() = default;
    void saveFile(std::vector<std::string> lines, std::string = "1");
    std::vector<std::string> readRoomFile();
    std::string glueFullPath();
    void setPath(std::string path) {this->path = path;}
    void setFileName(std::string name) {this->filename = name;}
private:
    std::string filename;
    std::string path = "/home/red/Uni/OOP/reworked/lab1/map/room/";
    std::string type = "savedRooms";
};


#endif //LAB1_TXTMNG_H