//
// Created by red on 05.11.2021.
//

#include "txtMng.h"

txtMng::txtMng(std::string filename, std::string type) {
    this->filename = filename;
    this->type = type;
}

std::string txtMng::glueFullPath() {
    std::string fullPath = this->path + this->type + "/" + this->filename + ".txt";
    return fullPath;
} //glue the path parts into fullpath
///MAYBE CHANGE THE PATH FIELD AND OTHER COMPONENTS INTO FULL PATH

void txtMng::saveFile(std::vector<std::string> lines, std::string name) {
    std::string path = glueFullPath();
    if (name != "1") {
        this->filename = name;
        path = glueFullPath();
    }
    std::cout << path << std::endl;
    std::ofstream outfile (path);
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[0].length(); j++) {
            outfile << lines[i][j];
        }
        outfile << std::endl;
    }
    outfile.close();
} //save STRINGS into NAME.txt file

std::vector<std::string> txtMng::readRoomFile() {
    std::vector<std::string> tmp;
    std::string p = glueFullPath();
    std::string line;
    std::ifstream infile (p, std::ios::in);
    while (std::getline(infile, line)) {
        tmp.emplace_back(line);
    }
    infile.close();
    return tmp;
} //read STRINGS from PATH
