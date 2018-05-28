//
// Created by kejbi on 22.05.18.
//

#include "armor.h"

Armor::Armor(int add_armor, int add_hp) : Thing(armor_type), add_armor(add_armor), add_hp(add_hp) {}

int Armor::getAdd_armor() const {
    return add_armor;
}

void Armor::setAdd_armor(int add_armor) {
    Armor::add_armor = add_armor;
}

int Armor::getAdd_hp() const {
    return add_hp;
}

void Armor::setAdd_hp(int add_hp) {
    Armor::add_hp = add_hp;
}
