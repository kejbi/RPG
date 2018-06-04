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

//weapon is type of thing
//improves damage and range of character when worn
class Weapon: public Thing{
private:
    weapon_type wt; //type of weapon (can be used in future ;P)
    int damage; //added damage
    int range; //new range

public:

    weapon_type getWt() const;

    void setWt(weapon_type wt);

    Weapon(weapon_type wt, int damage, int range);

    int getDamage() const;

    void setDamage(int damage);

    int getRange() const;

    void setRange(int range);


};
#endif //RPG_WEAPON_H
