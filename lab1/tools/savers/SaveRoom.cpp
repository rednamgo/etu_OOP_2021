//
// Created by red on 06.12.2021.
//

#include "SaveRoom.h"

void SaveRoom::save() {
    convert();
    std::string fullpath = this->path + "/" + this->filename + ".txt";
    std::cout << fullpath << std::endl;
    std::ofstream outfile (fullpath);
    for (int i = 0; i < this->data.size(); i++) {
        for (int j = 0; j < this->data[0].length(); j++) {
            outfile << this->data[i][j];
        }
        outfile << std::endl;
    }
    outfile.close();
    clearData();
}

void SaveRoom::convert() {
    std::vector<std::string> lines;
    std::string tmp = "";
    int height = this->room.getHeightWidth().first, width = this->room.getHeightWidth().second;
    //std::cout << height << "; " << width << std::endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            tmp += this->room.getTile(i, j)->getType();
        }
        lines.emplace_back(tmp);
        tmp.clear();
    }
    this->data = lines;
}

void SaveRoom::clearData() {
    this->filename.clear();
    for (int i = 0; i < this->data.size(); i++)
        this->data[i].clear();
    this->data.clear();
}
