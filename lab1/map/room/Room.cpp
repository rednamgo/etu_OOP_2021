//
// Created by red on 05.12.2021.
//

#include "Room.h"
//#include "../../../lab2/tools/overlays/Overlay.h"


Room::Room(int num, int height, int width, std::pair<int, int> entry, std::pair<int, int> exit) {
    this->num = num;
    this->height = height;
    this->width = width;
    this->entry = entry;
    this->exit = exit;
    this->array = new Tile * [height];
    for (int i = 0; i < height; i++)
        array[i] = new Tile [width];
}

Room::~Room() {
    for (int i = 0; i < this->height; i++) {
           delete [] array[i];
    }
    delete [] array;
} //destructor

Room::Room(const Room &other) {
    this->height = other.height;
    this->width = other.width;
    this->entry = other.entry;
    this->exit = other.exit;

    this->array = new Tile *[this->height];
    for (int i = 0; i < this->height; i++) this->array[i] = new Tile[this->width];

    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++)
            this->array[i][j] = other.array[i][j];
    }

} //copy constructor

Room &Room::operator=(const Room &other) {
    if (&other == this)
        return *this;

    for (int i = 0; i < this->height; i++) {
        delete [] array[i];
    } delete []array;

    this->height = other.height;
    this->width = other.width;
    this->num = other.num;

    this->array = new Tile * [height];

    for (int i = 0; i < this->height; i++)
    {
        this->array[i] = new Tile [width];
        for (int j = 0; j < this->width; j++)
            this->array[i][j] = other.array[i][j];
    }

    return *this;
} //copy operator

Room::Room(Room &&other) noexcept : height {other.height}, width {other.width}, array {other.array}, num {other.num},
entry{other.entry}, exit{other.exit} {
    std::swap(height, other.height);
    std::swap(width, other.width);
    std::swap(num, other.num);
    std::swap(entry, other.entry);
    std::swap(exit, other.exit);
    this->array = nullptr;
} //move constructor

Room& Room::operator=(Room&& other) noexcept {
    if (&other == this) return *this;

    std::swap(height, other.height);
    std::swap(width, other.width);
    std::swap(num, other.num);
    std::swap(entry, other.entry);
    std::swap(exit, other.exit);

    for (int i = 0; i < height; i++)
        delete []array[i];
    delete []array;

    return *this;
} //move operator

std::pair<int, int> Room::getHeightWidth() {
    std::pair<int,int> tmp(this->height, this->width);
    return tmp;
}

/*void Room::setEntity(IEntity *entity, int x, int y) {
    this->array[x][y].setEntity(entity);
}*/
/*
void Room::setOverlay() {
    //gridLocation *tmp = new gridLocation{entry.first, entry.second};
    std::vector<gridLocation> tmp = {{entry.first, entry.second}};
    this->overlay = new Overlay(this, &tmp);
}*/

void Room::setOverlay() {
    std::vector<gridLocation> tmp = {{entry.first, entry.second}};
    this->overlay = new PlayerSearchOverlay [2];
    for (int i = 0; i < 2; i++) {
        this->overlay[i].createOverlay(this);
    }
    this->overlay[1].flipIntoFleeOverlay();
}
