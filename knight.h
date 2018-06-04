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

    //reduces target's armor by half and deals damage + intelligence
    //false when out of range or no required statistics (mana, stamina, isalive)
    //20 mana 20 stamina

    bool precise_cut(Creature &cre);

    //renew some mana and health (20 + intelligene)
    //false when no required statistics (mana, stamina, isalive)
    //10 mana 20 stamina

    bool smart_choice();
};
#endif //RPG_KNIGHT_H
