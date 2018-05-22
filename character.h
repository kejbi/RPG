//
// Created by kejbi on 10.05.18.
//

#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H


#include "creature.h"

class Character: public Creature{
private:
    int mana; //mana of character (every special attack reduces it)
    int strength;
    int intelligence;
    int agility;
    int armor;
    
};
#endif //RPG_CHARACTER_H
