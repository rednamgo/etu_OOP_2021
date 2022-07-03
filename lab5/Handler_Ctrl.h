//
// Created by red on 11.05.22.
//

#ifndef REWORKED_HANDLER_CTRL_H
#define REWORKED_HANDLER_CTRL_H
#include "Controls.h"
#include "../lab1/map/room/Room.h"
#include "../lab2/creatures/player/Player.h"

class Handler_Ctrl {
public:
    Handler_Ctrl(Room *room): _room(room) {
        this->ctrl = Controls();
        ctrl.settings();
    };
    ~Handler_Ctrl() = default;

    void requestMove() {
        std::cout << "Your input>>";
        this->input = getchar();
        Player *player = this->_room->getPlayer();
        if (this->input == this->ctrl.down()) {
            player->move(DOWN, this->_room);
        }
        else if (this->input == this->ctrl.left()) {
            player->move(LEFT, this->_room);
        }
        else if (this->input == this->ctrl.up()) {;
            player->move(UP, this->_room);
        }
        else if (this->input == this->ctrl.right()) {
            player->move(RIGHT, this->_room);
        }

    }

private:
    Room *_room;
    Controls ctrl;
    char input;
};

#endif //REWORKED_HANDLER_CTRL_H
