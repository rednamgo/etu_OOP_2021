//
// Created by red on 07.12.2021.
//

#ifndef REWORKED_IPOTION_H
#define REWORKED_IPOTION_H
#include "../Item.h"
//#include "../../creatures/player/Player.h"

class IPotion: public Item {
public:
    virtual void interact(IEntity *) = 0;
    virtual void use(IEntity *) = 0;
    virtual int getType() = 0;
    virtual std::string getName() = 0;
    virtual bool isTaken() = 0;
    virtual void setTaken(bool t) = 0;
};


#endif //REWORKED_IPOTION_H
