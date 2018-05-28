//
// Created by kejbi on 10.05.18.
//

#include "creature.h"

int Creature::getHp() const {
    return hp;
}

int Creature::getPosX() const {
    return posX;
}

int Creature::getPosY() const {
    return posY;
}

const std::string &Creature::getName() const {
    return name;
}

void Creature::setHp(int hp) {
    Creature::hp = hp;
}

void Creature::setPosX(int posX) {
    Creature::posX = posX;
}

void Creature::setPosY(int posY) {
    Creature::posY = posY;
}

void Creature::setName(const std::string &name) {
    Creature::name = name;
}

int Creature::getAttackRange() const {
    return attackRange;
}

void Creature::setAttackRange(int attackRange) {
    Creature::attackRange = attackRange;
}

int Creature::getStamina() const {
    return stamina;
}

void Creature::setStamina(int stamina) {
    Creature::stamina = stamina;
}

bool Creature::move(int x, int y) {
    int dist=distance(x,y);
    if(dist*10>this->stamina){
        return false;
    }
    else{
        this->posX=x;
        this->posY=y;
        this->stamina-=dist*10;
    }

}

int Creature::getMax_hp() const {
    return max_hp;
}

void Creature::setMax_hp(int max_hp) {
    Creature::max_hp = max_hp;
}

int Creature::getMax_stamina() const {
    return max_stamina;
}

void Creature::setMax_stamina(int max_stamina) {
    Creature::max_stamina = max_stamina;
}

int Creature::distance(int x, int y) {
    return abs(this->posX-x)+abs(this->posY-y);
}

int Creature::getStrength() const {
    return strength;
}

void Creature::setStrength(int strength) {
    Creature::strength = strength;
}

int Creature::getIntelligence() const {
    return intelligence;
}

void Creature::setIntelligence(int intelligence) {
    Creature::intelligence = intelligence;
}

int Creature::getAgility() const {
    return agility;
}

void Creature::setAgility(int agility) {
    Creature::agility = agility;
}

int Creature::getArmor() const {
    return armor;
}

void Creature::setArmor(int armor) {
    Creature::armor = armor;
}


bool Creature::isIsalive() const {
    return isalive;
}

void Creature::setIsalive(bool isalive) {
    Creature::isalive = isalive;
}

int Creature::getDamage() const {
    return damage;
}

void Creature::setDamage(int damage) {
    Creature::damage = damage;
}

creature_type Creature::getCt() const {
    return ct;
}

void Creature::setCt(creature_type ct) {
    Creature::ct = ct;
}

Creature::Creature(creature_type ct, int hp, int posX, int posY, const std::string &name, int attackRange, int stamina,
                   int max_hp, int max_stamina, int strength, int intelligence, int agility, int armor, int damage,
                   bool isalive) : ct(ct), hp(hp), posX(posX), posY(posY), name(name), attackRange(attackRange),
                                   stamina(stamina), max_hp(max_hp), max_stamina(max_stamina), strength(strength),
                                   intelligence(intelligence), agility(agility), armor(armor), damage(damage),
                                   isalive(isalive) {}



