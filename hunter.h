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
    //when that skill executes mob (mob dies) hunter recieves 2+(lvl/5) x more exp
    //false when out of range or no required statistics (mana, stamina, isalive)
    //10 mana 20 stamina
    bool mob_executer(Mob &m);

    //pushes back from hunter (4 distance's units) and deals damage (damage- target's armor)
    //if target is in range of hunter and in straight line, target is pushed back in that line
    //if target is in range of hunter, but not in straight way, target is moved 2 x-coordinates and 2 y-coordinates further from hunter
    //false when out of range or no required statistics (mana, stamina, isalive)
    //20 mana 20 stamina
    bool get_out_of_my_face(Creature &cre);
};
#endif //RPG_HUNTER_H
