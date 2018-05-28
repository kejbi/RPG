//
// Created by kejbi on 28.05.18.
//

#include "mob.h"


int Mob::getExp_given() const {
    return exp_given;
}

void Mob::setExp_given(int exp_given) {
    Mob::exp_given = exp_given;
}

bool Mob::attack(Creature &cre) {
    if(this->isIsalive() && this->getStamina()-20>=0){

        if(distance(cre.getPosX(),cre.getPosY())>this->getAttackRange()){
            return false;
        }
        int cre_hp = cre.getHp();
        int damage_done;
        damage_done = this->getDamage()- cre.getArmor();
        if(damage_done<0){
            damage_done=0;
        }
        cre.setHp(cre_hp - damage_done);
        if(cre.getHp()<=0){
            cre.setIsalive(false);
        }
        this->setStamina(this->getStamina()-20);
        return true;
    }
    return false;
}

Mob::Mob(int hp, int posX, int posY, const std::string &name, int attackRange, int stamina,
         int max_hp, int max_stamina, int strength, int intelligence, int agility, int armor, int damage, bool isalive,
         int exp_given) : Creature(mob, hp, posX, posY, name, attackRange, stamina, max_hp, max_stamina, strength,
                                   intelligence, agility, armor, damage, isalive), exp_given(exp_given) {}
