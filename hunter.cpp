//
// Created by kejbi on 31.05.18.
//

#include "hunter.h"

Hunter::Hunter(int posX, int posY, const std::string &name) : Character(100, posX, posY, name, 1, 100, 100, 100,
                                                                        20, 0, 20,0, 20,
                                                                        true, 50, 50, 0, 200,
                                                                        1, 0) {}

Hunter::Hunter(int hp, int posX, int posY, const std::string &name, int attackRange, int stamina, int max_hp,
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

bool Hunter::mob_executer(Mob &m) {
    if(this->isalive && this->stamina-20>=0 && this->mana-10>=0){
        if(distance(m.getPosX(),m.getPosY())>this->attackRange){
            return false;
        }
        int damage_done;
        damage_done = this->damage- m.getArmor();
        if(damage_done<0){
            damage_done=0;
        }
        m.setHp(m.getHp() - damage_done);
        if(m.getHp()<=0){
            m.setIsalive(false);
            this->add_exp(m.getExp_given()*(2+(this->lvl)/5);
        }
        return true;
    }
    return false;
}

bool Hunter::get_out_of_my_face(Creature &cre) {
    if (this->isalive && this->mana - 20 >= 0 && this->stamina - 20 >= 0) {
        if (distance(cre.getPosX(), cre.getPosY()) > this -> attackRange) {
            return false;
        }
        int damage_done=this->damage-cre.getArmor();
        if(damage_done<0){
            damage_done=0;
        }
        cre.setHp(cre.getHp()-damage_done);
        if(this->posX==cre.getPosX()){
            if(this->posY<cre.getPosY()){
                cre.setPosY(cre.getPosY()+4);
            }
            else{
                cre.setPosY(cre.getPosY()-4);
            }
        }
        else if(this->posY==cre.getPosY()){
            if(this->posX<cre.getPosX()){
                cre.setPosY(cre.getPosY()+4);
            }
            else{
                cre.setPosX(cre.getPosX()-4);
            }
        }
        else if(this->posX<cre.getPosX()){
            if(this->posY<cre.getPosY()){
                cre.setPosX(cre.getPosX()+2);
                cre.setPosY(cre.getPosY()+2);
            }
            else{
                cre.setPosX(cre.getPosX()+2);
                cre.setPosY(cre.getPosY()-2);
            }
        }
        else if(this->posX>cre.getPosX()){
            if(this->posY<cre.getPosY()){
                cre.setPosX(cre.getPosX()-2);
                cre.setPosY(cre.getPosY()+2);
            }
            else{
                cre.setPosX(cre.getPosX()-2);
                cre.setPosY(cre.getPosY()-2);
            }
        }

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
