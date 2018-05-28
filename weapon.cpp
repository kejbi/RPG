//
// Created by kejbi on 22.05.18.
//

#include "weapon.h"


weapon_type Weapon::getWt() const {
    return wt;
}

void Weapon::setWt(weapon_type wt) {
    Weapon::wt = wt;
}



Weapon::Weapon(weapon_type wt, int damage, int range) : Thing(weapon), wt(wt), damage(damage),
                                                                       range(range) {}

int Weapon::getDamage() const {
    return damage;
}

void Weapon::setDamage(int damage) {
    Weapon::damage = damage;
}

int Weapon::getRange() const {
    return range;
}

void Weapon::setRange(int range) {
    Weapon::range = range;
}
