//
// Created by kejbi on 22.05.18.
//

#ifndef RPG_USABLE_H
#define RPG_USABLE_H

#include "thing.h"


//usable is type of thing
//usable renews some points of mana, stamina, hp

class Usable: public Thing{
private:
    int reg_mana; //regenerated mana
    int reg_stamina; //regenerated stamina
    int reg_hp; //regenerated hp
public:

    Usable(int reg_mana, int reg_stamina, int reg_hp);

    int getReg_mana() const;

    void setReg_mana(int reg_mana);

    int getReg_stamina() const;

    void setReg_stamina(int reg_stamina);

    int getReg_hp() const;

    void setReg_hp(int reg_hp);
};
#endif //RPG_USABLE_H
