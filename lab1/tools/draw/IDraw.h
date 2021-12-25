//
// Created by red on 05.12.2021.
//

#ifndef REWORKED_IDRAW_H
#define REWORKED_IDRAW_H
#include <iostream>
#include "../../map/room/Room.h"

class IDraw {
public:
    virtual void setChar(char) = 0;
    virtual void draw(Room *room) = 0;
};


#endif //REWORKED_IDRAW_H
