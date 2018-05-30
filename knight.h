//
// Created by kejbi on 30.05.18.
//

#ifndef RPG_KNIGHT_H
#define RPG_KNIGHT_H

#include "character.h"

class Knight: public Character{
public:
    Knight(int hp, int posX, int posY, const std::string &name, int attackRange, int stamina, int max_hp,
           int max_stamina, int strength, int intelligence, int agility, int armor, int damage, bool isalive, int mana,
           int max_mana, int exp, int next_lvl_exp, int lvl, int ability_point);

    Knight(int posX, int posY, const std::string &name);
    bool precise_cut(Creature &cre);
    bool smart_choice();
};
#endif //RPG_KNIGHT_H
