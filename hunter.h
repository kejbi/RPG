//
// Created by kejbi on 31.05.18.
//

#ifndef RPG_HUNTER_H
#define RPG_HUNTER_H

#include "character.h"
#include "mob.h"

class Hunter: public Character{
public:
    Hunter(int posX, int posY, const std::string &name);

    Hunter(int hp, int posX, int posY, const std::string &name, int attackRange, int stamina, int max_hp,
           int max_stamina, int strength, int intelligence, int agility, int armor, int damage, bool isalive, int mana,
           int max_mana, int exp, int next_lvl_exp, int lvl, int ability_point);
    bool mob_executer(Mob &m);
    bool get_out_of_my_face(Creature &cre);
};
#endif //RPG_HUNTER_H
