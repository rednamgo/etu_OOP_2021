//
// Created by red on 07.12.2021.
//

#ifndef REWORKED_ITEM_H
#define REWORKED_ITEM_H
#include "../IEntity.h"
#include "../creatures/Actor.h"

class Item: public IEntity {
public:
    virtual void interact(IEntity *) = 0;
    virtual int getType() = 0;
    virtual std::string getName() = 0;
    virtual bool isTaken() = 0;
    virtual void setTaken(bool t) = 0;

};

#endif //REWORKED_ITEM_H
