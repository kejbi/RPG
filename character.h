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
    int max_mana; //maximum mana
    int exp; //experiance, required to reaching next levels of character
    int next_lvl_exp; //experiance needed to next level;
    int lvl; //current level of character
    int ability_point; //ability points allows to improve statistics of character (1 point for each lvlup)
    Weapon* wp; //worn weapon
    Armor* armor_thing; //worn armor
    std::vector<Thing*> eq; //equipment

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

    //comments in definition
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

    //character uses thing from eq (i is index of item in eq)
    //if thing is weapon, character wears it, increases damage and range (in case when weapon is worn already, old one is replaced with new)
    //if armor_thing , character wears it, increases armor and max_hp (in case when armor_thing is worn already, old one is replaced with new)
    //if usable, character consume it

    void use(int i);

    //replaces weapon or armor_thing to eq, reduces exact statistics
    void putOff(Thing *th);

    //adds thing to eq
    void add_to_eq(Thing *th);
    //removes thing from eq
    void drop_from_eq(int i);

    //checks if character has enough exp to get next lvl
    //if so, exp is reduced by next_lvl_exp and next lvl_exp is increased
    void lvl_up();


    //adds exp and then uses function lvl_up
    //every time exp is added, character can lvl_up
    void add_exp(int ae);

    //add 10 to strength
    void improve_strength();

    //add 10 to agility
    void improve_agility();

    //add 10 to intelligence
    void improve_intelligence();

    //hp = max_hp
    void renew_Hp();

    //stamina=max_stamina
    void renew_Stamina();

    //mana = max_mana
    void renew_Mana();

    //when character is dead, makes it again alive, renews mana, hp, stamina and loses current exp of character
    void revive();



};
#endif //RPG_CHARACTER_H
