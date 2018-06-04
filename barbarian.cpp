//
// Created by kejbi on 28.05.18.
//

#include "barbarian.h"
#include "mob.h"

Barbarian::Barbarian(int posX, int posY, const std::string &name) : Character(100, posX, posY, name,
                                                                                                  1, 100,
                                                                                                  100, 100,
                                                                                                  30,
                                                                                                  0, 10,
                                                                                                  0, 30,
                                                                                                  true, 50, 50, 0,
                                                                                                  200, 1,
                                                                                                  0) {}

Barbarian::Barbarian(int hp, int posX, int posY, const std::string &name, int attackRange, int stamina, int max_hp,
                     int max_stamina, int strength, int intelligence, int agility, int armor, int damage, bool isalive,
                     int mana, int max_mana, int exp, int next_lvl_exp, int lvl, int ability_point) : Character(hp, posX, posY, name,
                                                                                                  attackRange, stamina,
                                                                                                  max_hp, max_stamina,
                                                                                                  strength,
                                                                                                  intelligence, agility,
                                                                                                  armor, damage,
                                                                                                  isalive, mana, max_mana, exp,
                                                                                                  next_lvl_exp, lvl,
                                                                                                  ability_point) {}

bool Barbarian::charge(Creature &cre, int x, int y) {
    if(this->isalive && this->mana-25>=0 && this->stamina-20>=0) {
        if (distance(x,y)> 4+((this->lvl)/5)) {
            return false;
        }
        this->posX=x;
        this->posY=y;
        if(distance(cre.getPosX(), cre.getPosY()) ==1){
            int damage_done=this->strength-cre.getArmor();
            if(damage_done<0){
                damage_done=0;
            }
            int self_damage=50+this->lvl-this->intelligence;
            if(self_damage<0){
                self_damage=0;
            }
            cre.setHp(cre.getHp()-damage_done);
            this->hp-=self_damage;
            if(cre.getHp()<=0){
                cre.setIsalive(false);
                if(cre.getCt()==mob){
                    Creature *c;
                    c=&cre;
                    Mob* m= static_cast<Mob*>(c);
                    this->add_exp(m->getExp_given());
                }
            }
            if(this->hp<=0){
                this->isalive=false;
            }

        }
        this->mana-=25;
        this->stamina-=20;
        return true;

    }
    return false;
}

bool Barbarian::stone_throw(Creature &cre) {
    if (this->isalive && this->mana - 15 >= 0 && this->stamina - 20 >= 0) {
        if (distance(cre.getPosX(), cre.getPosY()) > 2 + ((this->lvl) / 5)) {
            return false;
        }
        int damage_done=(this->strength)/2+this->intelligence-cre.getArmor();
        if(damage_done<0){
            damage_done=0;
        }
        cre.setHp(cre.getHp()-damage_done);
        if(cre.getHp()<=0){
            cre.setIsalive(false);
            if(cre.getCt()==mob){
                Creature *c;
                c=&cre;
                Mob* m= static_cast<Mob*>(c);
                this->add_exp(m->getExp_given());
            }
        }
        this->mana-=15;
        this->stamina-=20;
        return true;
    }
    return false;
}