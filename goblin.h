//
// Created by kejbi on 28.05.18.
//

#ifndef RPG_GOBLIN_H
#define RPG_GOBLIN_H

#include "mob.h"

class Goblin: public Mob{
public:
    Goblin(int posX, int posY);

    Goblin(int hp, int posX, int posY, const std::string &name, int attackRange, int stamina, int max_hp,
           int max_stamina, int strength, int intelligence, int agility, int armor, int damage, bool isalive,
           int exp_given);
};
#endif //RPG_GOBLIN_H
