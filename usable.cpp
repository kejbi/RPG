//
// Created by kejbi on 22.05.18.
//

#include "usable.h"


int Usable::getReg_mana() const {
    return reg_mana;
}

void Usable::setReg_mana(int reg_mana) {
    Usable::reg_mana = reg_mana;
}

int Usable::getReg_stamina() const {
    return reg_stamina;
}

void Usable::setReg_stamina(int reg_stamina) {
    Usable::reg_stamina = reg_stamina;
}

int Usable::getReg_hp() const {
    return reg_hp;
}

void Usable::setReg_hp(int reg_hp) {
    Usable::reg_hp = reg_hp;
}

Usable::Usable(int reg_mana, int reg_stamina, int reg_hp) : Thing(usable), reg_mana(reg_mana),
                                                                           reg_stamina(reg_stamina), reg_hp(reg_hp) {}
