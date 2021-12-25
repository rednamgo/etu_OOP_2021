//
// Created by red on 07.12.2021.
//

#ifndef REWORKED_IWEAPON_H
#define REWORKED_IWEAPON_H
#include "../Item.h"
//#include "../../creatures/player/Player.h"
#include "../potions/IPotion.h"

class IWeapon: public Item {
public:
    virtual int getATK() = 0;
    virtual int getRNGE() = 0;
    virtual void setEffect(IPotion *) = 0;
    virtual void interact(IEntity *) = 0;
    virtual int getType() = 0;
};


#endif //REWORKED_IWEAPON_H
