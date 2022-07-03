//
// Created by red on 05.12.2021.
//

#include "RoomGenerator.h"

void RoomGenerator::generate() {
    if (this->isFromFile) {
        readFromFile(1);
        return;
    } ///add NUM READER

    randNum rng;
    this->room->setHeight(rng.getRand(MIN_SIZE, MAX_SIZE));
    this->room->setWidth(rng.getRand(MIN_SIZE, MAX_SIZE));

    Tile **tmparr;
    tmparr = new Tile * [this->room->getHeightWidth().first];
    for (int i = 0; i < this->room->getHeightWidth().first; i++) {
        tmparr[i] = new Tile [this->room->getHeightWidth().second];
    }
    this->room->setArray(tmparr);

    std::pair<int, int> tmp;
    for (int i = 0; i < this->room->getHeightWidth().first; i++) {
        tmp.first = i;
        for (int j = 0; j < this->room->getHeightWidth().second; j++) {
            tmp.second = j;
            setWall(tmp);
        }
    }
    //std::cout << this->room->getHeightWidth().first << " " << this->room->getHeightWidth().second << std::endl;
    createEntry();
    createTunnels();
    room->setOverlay();
}

void RoomGenerator::createEntry() {
    std::pair<int, int> xy(this->room->getEntry().first, this->room->getEntry().second);
    int tmp = this->room->getHeightWidth().first - 2;
    randNum rng;
    xy.first = rng.getRand(0, tmp); //height - 2
    if (xy.first) xy.second = 0;
    else {
        tmp = this->room->getHeightWidth().second - 2;
        xy.second = rng.getRand(1, tmp);
    }
    setEntry(xy);
}

void RoomGenerator::createTunnels() {
    randNum rng;
    int maxLen, tunLen = 0, rndLen, maxTunnels, direction = UP, cur_x, cur_y;
    int prevDir = LEFT;
    int height = this->room->getHeightWidth().first, width = this->room->getHeightWidth().second;
    int exitX = 0, exitY = 0, tmpMax = 0;
    int entryX = this->room->getEntry().first, entryY = this->room->getEntry().second;
    std::pair<int, int> xy;

    maxLen = rng.getRand(height/2, height - 1);
    maxTunnels = rng.getRand(height, (height - 1) * (width - 1));

    cur_x = entryX;
    if (!cur_x) {
        cur_x++;
        cur_y = entryY;
    }
    else cur_y = this->room->getEntry().second + 1;
    exitX = cur_x;
    exitY = cur_y;

    while (maxTunnels && maxLen) {
        do {
            direction = rng.getRand(UP, LEFT);
        } while (direction == prevDir);
        rndLen = rng.getRand(1, maxLen);

        while (tunLen < rndLen) {
            if (cur_y == 1 && direction == LEFT || cur_x == 1 && direction == UP ||
                cur_x >= height - 2 && direction == DOWN || cur_y >= width - 2 && direction == RIGHT)
                break;
            xy.first = cur_x;
            xy.second = cur_y;
            this->setFloor(xy);
            if (direction == UP) cur_x--;
            else if (direction == DOWN) cur_x++;
            else if (direction == LEFT) cur_y--;
            else if (direction == RIGHT) cur_y++;
            tunLen++;
        }
            if (tunLen) {
                if (exitY < cur_y || exitX < cur_x) {
                    exitY = cur_y;
                    exitX = cur_x;
                }
                prevDir = direction;
                maxTunnels--;
                tunLen = 0;
            }
        }
    xy.first = exitX;
    xy.second = exitY + 1;
    setExit(xy);
}


void RoomGenerator::readFromFile(int num) {
    txtMng mng(std::to_string(num), "savedRooms");
    std::vector<std::string> lines = mng.readRoomFile();
    Tile **tmparr;
    int height = lines.size(), width = lines[0].length();
    this->room->setWidth(width);
    this->room->setHeight(height);
    tmparr = new Tile * [height];
    for (int i = 0, k = 0; i < height && k < lines.size(); i++, k++) {
        tmparr[i] = new Tile [width];
        for (int j = 0, m = 0; j < width && m < lines[i].length(); j++, m++) {
            tmparr[i][j].setType(lines[k][m]);
        }
    }
    this->room->setArray(tmparr);
}

void RoomGenerator::saveIntoFile(std::string name) {
    std::vector<std::string> lines;
    std::string tmp = "";
    int height = this->room->getHeightWidth().first, width = this->room->getHeightWidth().second;
    txtMng mng(name, "savedRooms");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            tmp += this->room->getTile(i, j)->getType();
        }
        lines.emplace_back(tmp);
        tmp.clear();
    }
    mng.saveFile(lines, name);
}

void RoomGenerator::setWall(std::pair<int, int> xy) {
    this->room->getTile(xy.first, xy.second)->setType(WALL);
}

void RoomGenerator::setEntry(std::pair<int, int> xy) {
    this->room->getTile(xy.first, xy.second)->setType(ENTRANCE);
    this->room->setEntry(xy.first, xy.second);
}

void RoomGenerator::setFloor(std::pair<int, int> xy) {
    this->room->getTile(xy.first, xy.second)->setType(FLOOR);
}

void RoomGenerator::setExit(std::pair<int, int> xy) {
    this->room->getTile(xy.first, xy.second)->setType(EXIT);
    this->room->setExit(xy.first, xy.second);
}
