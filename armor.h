//
// Created by kejbi on 22.05.18.
//

#ifndef RPG_ARMOR_H
#define RPG_ARMOR_H

#include "thing.h"

class Armor: public Thing{
private:
    int add_armor;
public:
    int getAdd_armor() const;

    void setAdd_armor(int add_armor);

    int getAdd_hp() const;

    void setAdd_hp(int add_hp);

private:
    int add_hp;
public:
    Armor(int add_armor, int add_hp);
};
#endif //RPG_ARMOR_H
