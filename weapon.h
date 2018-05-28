//
// Created by kejbi on 22.05.18.
//

#ifndef RPG_WEAPON_H
#define RPG_WEAPON_H

#include "thing.h"
enum weapon_type{
    bow,
    sword
};
class Weapon: public Thing{
public:

    weapon_type getWt() const;

    void setWt(weapon_type wt);

    Weapon(weapon_type wt, int damage, int range);

    int getDamage() const;

    void setDamage(int damage);

    int getRange() const;

    void setRange(int range);

private:
    weapon_type wt;
    int damage;
    int range;

};
#endif //RPG_WEAPON_H
