//
// Created by red on 10.05.22.
//

#include "../lab2/tools/generators/EntityGenerator.h"
#include "../lab1/map/Map.h"
#include "../lab1/tools/generators/RoomGenerator.h"

#include "rules/Rules_roomClear.h"

#include "../lab1/tools/draw/RoomDraw.h"

#include "Game.h"
#include "../lab5/Handler_Ctrl.h"
#include "../lab5/Menu_Draw.h"

void Game::start() {
    //----random room initialization
    Room *room = new Room;
    Room *currRoom = room;
    RoomGenerator gen(room);
    Placement placer;
    gen.generate();
    EntityGenerator egen(room);
    egen.generate();

    Player *player = room->getPlayer();
    //-----

    //-----rules initialization
    static std::string presetName = "ENEMIES_CLEAR";
    Rules_roomClear<presetName> rRules(*currRoom);
    rRules.preset();
    //-----

    //-----decorators initialization
    RoomDraw drawR;
    MenuDraw info_drawer;
    //-----

    //-----controls initialization
    Handler_Ctrl ctrl(currRoom);
    //-----

    while (!rRules.lose()) {
        std::cout << "\x1B[2J\x1B[H";

        drawR.draw(currRoom);

        info_drawer.print(currRoom);

        ctrl.requestMove();
        for (auto i: currRoom->getEntities()) {
            if (currRoom->getEnemyCnt() > 0) {
                auto j = dynamic_cast<IEnemy*>(i);
                if (j && !j->isDead()) j->act(*player, currRoom);
            }
            else break;
        }

        if (rRules.win()) {
            std::cout << "\n>>YOU WIN<<\n";
            break;
        }

        if (rRules.lose()) {
            std::cout << "\n>>YOU`VE LOST<<\n";
            break;
        }

    }

}
