//
// Created by kejbi on 10.05.18.
//

#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H


#include <vector>
#include "creature.h"
#include "weapon.h"
#include "armor.h"
#include "usable.h"

class Character: public Creature{
protected:
    int mana; //mana of character (every special attack reduces it)
    int max_mana;
    int exp;
    int next_lvl_exp;
    int lvl;
    int ability_point;
    Weapon* wp;
    Armor* armor_thing;
    std::vector<Thing*> eq;

public:
    Character(int hp, int posX, int posY, const std::string &name, int attackRange, int stamina,
              int max_hp, int max_stamina, int strength, int intelligence, int agility, int armor, int damage,
              bool isalive, int mana, int max_mana, int exp, int next_lvl_exp, int lvl, int ability_point);

    int getAbility_point() const;

    void setAbility_point(int ability_point);

    int getMax_mana() const;

    void setMax_mana(int max_mana);

    const std::vector<Thing *> &getEq() const;

    void setEq(const std::vector<Thing *> &eq);

    bool attack(Creature &cre) override;

    int getMana() const;

    void setMana(int mana);

    int getExp() const;

    void setExp(int exp);

    int getNext_lvl_exp() const;

    void setNext_lvl_exp(int next_lvl_exp);

    int getLvl() const;

    void setLvl(int lvl);

    Weapon *getWeapon() const;

    void setWeapon(Weapon *weapon);

    Armor *getArmor_thing() const;

    void setArmor_thing(Armor *armor_thing);

    void use(int i);

    void putOff(Thing *th);

    void add_to_eq(Thing *th);

    void drop_from_eq(int i);

    void lvl_up();

    void add_exp(int ae);

    void improve_strength();

    void improve_agility();

    void improve_intelligence();

    void renew_Hp();

    void renew_Stamina();

    void renew_Mana();



};
#endif //RPG_CHARACTER_H
