//
// Created by red on 12.12.2021.
//

#ifndef REWORKED_ENTITYGENERATOR_H
#define REWORKED_ENTITYGENERATOR_H
#include "../../../lab1/tools/generators/IGenerate.h"
#include "../../../lab1/tools/generators/randNum.h"
//#include "../../IEntity.h"
#include "../../creatures/enemies/melee/Knight.h"
#include "../../creatures/enemies/melee/Demon.h"
#include "../../creatures/enemies/longrange/Mage.h"
#include "../../items/potions/HPotion.h"
#include "../../items/potions/Poison.h"
#include "../../items/weapons/Dagger.h"

enum minDistGen {
    ENEMY_DIST = 8,
    ITEM_DIST = 20
};

enum enemyTypes {
    KNIGHT = 1,
    DEMON = 2,
    MAGE = 3
};

enum itemTypes {
    HPOTION = 1,
    POISON = 2,
    DAGGER = 3
};

class EntityGenerator: IGenerate {
public:
    EntityGenerator() = default;
    EntityGenerator(Room *room) :room(room) {};
    ~EntityGenerator();
    void generate() override;
    void setFreeTiles();
    void setEnemyNum();
    void setItemNum();
    void generatePlayer();
    void generateEnemies(gridLocation &spawnXY, int &minTile, int index);
    static IEnemy *createEnemy(int type);
    void generateItems(gridLocation &spawnXY, int &minTile, int index);
    static Item *createItem(int type);
    void spawn(int type);
private:
    Room *room;
    int entityNum = 0;
    std::vector<gridLocation> freeTiles;
};


#endif //REWORKED_ENTITYGENERATOR_H
