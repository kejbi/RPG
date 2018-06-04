//
// Created by kejbi on 22.05.18.
//

#ifndef RPG_ARMOR_H
#define RPG_ARMOR_H

#include "thing.h"


//armor is type of thing
//improves armor and max_hp of character when worn
class Armor: public Thing{
private:
    int add_armor; //armor added to character armor
    int add_hp; //added hp to max_hp
public:
    int getAdd_armor() const;

    void setAdd_armor(int add_armor);

    int getAdd_hp() const;

    void setAdd_hp(int add_hp);

    Armor(int add_armor, int add_hp);
};
#endif //RPG_ARMOR_H
