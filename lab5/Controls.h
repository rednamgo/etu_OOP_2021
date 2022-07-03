//
// Created by red on 11.05.22.
//

#ifndef REWORKED_CONTROLS_H
#define REWORKED_CONTROLS_H
#include <iostream>

enum DefaultKeys {
    K_UP = 'w',
    K_DOWN = 's',
    K_LEFT = 'a',
    K_RIGHT = 'd'
};

class Controls {
public:
    Controls():_key_UP(K_UP), _key_RIGHT(K_RIGHT), _key_LEFT(K_LEFT), _key_DOWN(K_DOWN) {};
    ~Controls() = default;
    void settings() {
        char ch;
        clear();
        displayControls();
        std::cout << "Do you wish to use default keys for controls?(y/n):";
        std::cin >> ch;
        if (ch == 'n' || ch == 'N') setControls();
    }
    void setControls() {
        std::cout << "Press key for..." << std::endl;
        std::cout << "\tUP: ";
        std::cin >> this->_key_UP;
        std::cout << "\tDOWN: ";
        std::cin >> this->_key_DOWN;
        std::cout << "\tLEFT: ";
        std::cin >> this->_key_LEFT;
        std::cout << "\tRIGHT: ";
        std::cin >> this->_key_RIGHT;
        displayControls();
    };
    void displayControls() const {
        std::cout << "Controls now are: " << std::endl << "\t" << _key_UP << _key_LEFT << _key_DOWN << _key_RIGHT << " to move"
            << std::endl;
    };

    char right() const {return this->_key_RIGHT;}
    char left() const {return this->_key_LEFT;}
    char down() const {return this->_key_DOWN;}
    char up() const {return this->_key_UP;}

private:
    char _key_UP, _key_DOWN, _key_LEFT, _key_RIGHT;
};



#endif //REWORKED_CONTROLS_H
