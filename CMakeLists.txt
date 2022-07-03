cmake_minimum_required(VERSION 3.21)
project(reworked)

set(CMAKE_CXX_STANDARD 20)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(reworked main.cpp lab1/map/room/Tile.cpp lab1/map/room/Tile.h
        lab1/map/room/Room.cpp lab1/map/room/Room.h lab2/IEntity.h
        lab1/tools/draw/IDraw.h lab1/tools/generators/IGenerate.h
        lab1/tools/generators/RoomGenerator.cpp lab1/tools/generators/RoomGenerator.h
        lab1/tools/generators/randNum.h lab1/tools/txtMng.cpp lab1/tools/txtMng.h
        lab1/tools/draw/RoomDraw.h lab1/map/Map.cpp lab1/map/Map.h
        lab1/tools/generators/MapGenerator.cpp lab1/tools/generators/MapGenerator.h
        lab1/tools/savers/ISaver.h lab1/tools/savers/SaveRoom.cpp lab1/tools/savers/SaveRoom.h
        lab2/creatures/Actor.cpp lab2/creatures/Actor.h lab2/creatures/player/Player.cpp
        lab2/creatures/player/Player.h lab2/items/Item.h lab2/items/weapons/IWeapon.h
        lab2/items/potions/HPotion.cpp lab2/items/potions/HPotion.h lab2/creatures/enemies/IEnemy.h
        lab2/items/potions/IPotion.h lab2/items/weapons/Dagger.cpp lab2/items/weapons/Dagger.h
        lab2/tools/Direction.h lab2/items/potions/Poison.cpp lab2/items/potions/Poison.h
        lab2/creatures/enemies/melee/Knight.cpp lab2/creatures/enemies/melee/Knight.h
        lab2/creatures/enemies/AI/AI.h lab2/creatures/enemies/melee/Demon.cpp
        lab2/creatures/enemies/melee/Demon.h lab2/creatures/enemies/longrange/Mage.cpp
        lab2/creatures/enemies/longrange/Mage.h lab2/tools/overlays/Overlay.cpp
        lab2/tools/overlays/Overlay.h lab2/tools/Placement.cpp lab2/tools/Placement.h
        lab2/tools/generators/EntityGenerator.cpp lab2/tools/generators/EntityGenerator.h
        lab2/tools/overlays/PlayerSearchOverlay.cpp lab2/tools/overlays/PlayerSearchOverlay.h
        lab2/creatures/enemies/AI/MovementBehavior.h lab2/creatures/enemies/AI/DeathBehavior.h
        lab2/creatures/enemies/AI/AttackBehavior.h lab2/creatures/enemies/AI/AI.cpp
        lab2/creatures/enemies/AI/MovementBehavior.cpp lab4/rules/Rules_roomClear.h lab4/rules/Rules_mapClear.h lab4/rules/Presets_roomClear.h lab4/Game.cpp lab4/Game.h lab5/Controls.h lab5/Handler_Ctrl.h lab5/Menu_Draw.h)

target_link_libraries(reworked ${CURSES_LIBRARIES})
