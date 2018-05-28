//
// Created by kejbi on 28.05.18.
//

#ifndef RPG_BARBARIAN_H
#define RPG_BARBARIAN_H

#include "character.h"

class Barbarian: public Character{
public:
    Barbarian(int posX, int posY, const std::string &name);

    Barbarian(int hp, int posX, int posY, const std::string &name, int attackRange, int stamina, int max_hp,
              int max_stamina, int strength, int intelligence, int agility, int armor, int damage, bool isalive,
              int mana, int exp, int next_lvl_exp, int lvl, int ability_point);
};
#endif //RPG_BARBARIAN_H
