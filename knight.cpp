//
// Created by kejbi on 30.05.18.
//

#include "knight.h"
#include "mob.h"

Knight::Knight(int hp, int posX, int posY, const std::string &name, int attackRange, int stamina, int max_hp,
               int max_stamina, int strength, int intelligence, int agility, int armor, int damage, bool isalive,
               int mana, int max_mana, int exp, int next_lvl_exp, int lvl, int ability_point) : Character(hp, posX,
                                                                                                          posY, name,
                                                                                                          attackRange,
                                                                                                          stamina,
                                                                                                          max_hp,
                                                                                                          max_stamina,
                                                                                                          strength,
                                                                                                          intelligence,
                                                                                                          agility,
                                                                                                          armor, damage,
                                                                                                          isalive, mana,
                                                                                                          max_mana, exp,
                                                                                                          next_lvl_exp,
                                                                                                          lvl,
                                                                                                          ability_point) {}

Knight::Knight(int posX, int posY, const std::string &name) : Character(100, posX,
                                                                        posY, name,
                                                                        1, 100,100, 100, 20, 10, 10, 5, 20, true, 100,
                                                                        100, 0, 200, 1, 0) {}

bool Knight::precise_cut(Creature &cre) {
    if (this->isalive && this->mana - 20 >= 0 && this->stamina - 20 >= 0) {
        if (distance(cre.getPosX(), cre.getPosY()) > 1) {
            return false;
        }
        int damage_done=(this->damage)-(cre.getArmor()/2-this->intelligence);
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
        this->mana-=20;
        this->stamina-=20;
        return true;
    }
}

bool Knight::smart_choice() {
    if (this->isalive && this->mana - 20 >= 0 && this->stamina - 20 >= 0) {
        if(this->hp+this->intelligence+20>this->max_hp){
            this->hp=this->max_hp;
        }
        else{
            this->hp+=this->intelligence+20;
        }
        if(this->mana+this->intelligence+20>this->max_mana){
            this->mana=this->max_mana;
        }
        else{
            this->mana+=this->intelligence+20;
        }
        if(this->stamina+this->intelligence+20>this->max_stamina){
            this->stamina=this->max_stamina;
        }
        else{
            this->stamina+=this->intelligence+20;
        }
        return true;
    }
    return false;
}
