//
// Created by red on 05.12.2021.
//

#ifndef REWORKED_RANDNUM_H
#define REWORKED_RANDNUM_H
#include "IGenerate.h"
#include <random>

class randNum: IGenerate {
public:
    randNum() = default;
    void generate() override {
            std::random_device rd; // obtain a random number from hardware
            std::mt19937 gen(rd()); // seed the generator
            std::uniform_int_distribution<> distr(min, max); // define the range
            this->rand = distr(gen);
    }
    void setMinMax(int min, int max) {this->min = min; this->max = max;}
    int getRand(int min, int max) { setMinMax(min, max); generate(); return this->rand;}
private:
    int min, max;
    int rand;
};


#endif //REWORKED_RANDNUM_H
