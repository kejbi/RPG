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
              int mana, int max_mana, int exp, int next_lvl_exp, int lvl, int ability_point);

    //charge must have target (creature), x, y are coordinates where barbarian will be moved
    //if barbarian is in distance equal 1 from creature creature will recieve damage (strength (not damage) - target's armor), also
    // barbarian gets self damage (50 + lvl - intelligence)
    //if target is out of range, barbarian is just moved to (x,y) with no self damage
    //false when out of range or no required statistics (mana, stamina, isalive)
    //25 mana 20 stamina
    bool charge(Creature &cre, int x, int y);
    //barbarian throws stone in direction of creature (target), deals damage to target (strength/2 + intelligence - target's armor)
    //range is 2+ (lvl/5) (+1 for 5 levels)
    //false when out of range or no required statistics (mana, stamina, isalive)
    // 15 mana 20 stamina
    bool stone_throw(Creature &cre);
};
#endif //RPG_BARBARIAN_H
