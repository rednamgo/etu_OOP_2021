//
// Created by red on 08.12.2021.
//

#ifndef REWORKED_POISON_H
#define REWORKED_POISON_H

#include "IPotion.h"
#include "../../creatures/player/Player.h"

class Poison: public IPotion {
public:
    Poison() = default;
    ~Poison() = default;
    void interact(IEntity *) override; //if player -> store it; else - use it
    void use(IEntity *) override;
    int getType() override {return 2;}
    std::string getName() override {return "Poison";}
    bool isTaken() {return this->taken;}
    void setTaken(bool t) {this->taken = t;}

private:
    int DMGVal = 5;
    int turns = 3;
    bool taken = false;
    gridLocation xy;
};

#endif //REWORKED_POISON_H
