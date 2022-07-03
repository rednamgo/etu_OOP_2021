//
// Created by red on 07.12.2021.
//

#ifndef REWORKED_DAGGER_H
#define REWORKED_DAGGER_H
#include "IWeapon.h"
#include "../potions/IPotion.h"
#include "../../creatures/player/Player.h"

class Dagger: public IWeapon{
public:
    Dagger() = default;
    ~Dagger() = default;
    int getATK() override;
    int getRNGE() override;
    void setEffect(IPotion *) override;
    void interact(IEntity *) override;
    int getType() override {return 1;}
    std::string getName() override {return "Dagger";}
    bool isTaken() {return this->taken;}
    void setTaken(bool t) {this->taken = t;}
private:
    int ATK = 10, RNG = 1;
    IPotion *potion;
    bool taken = false;
    gridLocation xy;
};


#endif //REWORKED_DAGGER_H
