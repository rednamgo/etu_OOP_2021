//
// Created by red on 07.12.2021.
//

#ifndef REWORKED_HPOTION_H
#define REWORKED_HPOTION_H
#include "IPotion.h"
#include "../../creatures/player/Player.h"

class HPotion: public IPotion {
public:
    HPotion() = default;
    ~HPotion() = default;
    void interact(IEntity *) override; //check if player; yes -> store in inventory; else -> use it on target
    void use(IEntity *) override; //check if HP overlaps and add points till maxHP
    int getType() override {return 3;}
private:
    int healVal = 20;
};


#endif //REWORKED_HPOTION_H
