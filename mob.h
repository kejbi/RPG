//
// Created by kejbi on 28.05.18.
//

#ifndef RPG_MOB_H
#define RPG_MOB_H

#include "creature.h"

class Mob: public Creature{
private:
    int exp_given;
public:
    Mob(int hp, int posX, int posY, const std::string &name, int attackRange, int stamina, int max_hp,
        int max_stamina, int strength, int intelligence, int agility, int armor, int damage, bool isalive,
        int exp_given);

    int getExp_given() const;

    void setExp_given(int exp_given);

    bool attack(Creature &cre) override;
};
#endif //RPG_MOB_H
