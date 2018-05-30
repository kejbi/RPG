//
// Created by kejbi on 10.05.18.
//

#include "character.h"
#include "usable.h"
#include "mob.h"

bool Character::attack(Creature &cre) {
    if(this->isIsalive() && this->getStamina()-20>=0){

        if(distance(cre.getPosX(),cre.getPosY())>this->getAttackRange()){
            return false;
        }
        else {
            int cre_hp = cre.getHp();
            int damage_done;
            damage_done = this->getDamage()- cre.getArmor();
            if(damage_done<0){
                damage_done=0;
            }
            cre.setHp(cre_hp - damage_done);
            if(cre.getHp()<=0){
                cre.setIsalive(false);
                if(cre.getCt()==mob){
                    Creature *c;
                    c=&cre;
                    Mob* m= static_cast<Mob*>(c);
                    this->add_exp(m->getExp_given());
                }
            }
                // counter
            else if(distance(cre.getPosX(),cre.getPosY())<=cre.getAttackRange()){
                int random=rand()%500;
                if(random+cre.getAgility()>400);{
                    this->setHp(this->getHp()-cre.getDamage()+this->getArmor());
                }
            }
            this->setStamina(this->getStamina()-20);
            return true;
        }
    }
    return false;


}



int Character::getMana() const {
    return mana;
}

void Character::setMana(int mana) {
    Character::mana = mana;
}

int Character::getExp() const {
    return exp;
}

void Character::setExp(int exp) {
    Character::exp = exp;
}

int Character::getNext_lvl_exp() const {
    return next_lvl_exp;
}

void Character::setNext_lvl_exp(int next_lvl_exp) {
    Character::next_lvl_exp = next_lvl_exp;
}

int Character::getLvl() const {
    return lvl;
}

void Character::setLvl(int lvl) {
    Character::lvl = lvl;
}

Weapon *Character::getWeapon() const {
    return wp;
}

void Character::setWeapon(Weapon *weapon) {
    Character::wp = weapon;
}

Armor *Character::getArmor_thing() const {
    return armor_thing;
}

void Character::setArmor_thing(Armor *armor_thing) {
    Character::armor_thing = armor_thing;
}



void Character::use(int i) {
    if(this->isIsalive()){
        if(eq[i]->getTt()==weapon){
            if(this->getWeapon()== nullptr){
                this->setWeapon(static_cast<Weapon*>(eq[i]));
                this->setDamage(this->getStrength()+wp->getDamage());
                this->setAttackRange(this->getAttackRange()+wp->getRange());
                eq.erase(eq.begin()+i);
            }
            else{
                Weapon* temp;
                temp=this->getWeapon();
                this->setDamage(this->getStrength());
                this->setAttackRange(this->getAttackRange()-wp->getRange());
                this->setWeapon(static_cast<Weapon*>(eq[i]));
                this->setDamage(this->getStrength()+wp->getDamage());
                this->setAttackRange(this->getAttackRange()+wp->getRange());
                eq[i]=temp;
            }

        }
        if(eq[i]->getTt()==armor_type){
            if(this->getArmor_thing()== nullptr){
                this->setArmor_thing(static_cast<Armor*>(eq[i]));
                this->setArmor(this->getArmor()+armor_thing->getAdd_armor());
                this->setMax_hp(this->getMax_hp()+armor_thing->getAdd_hp());
                eq.erase(eq.begin()+i);
            }
            else{
                Armor* temp;
                temp=this->getArmor_thing();
                this->setArmor(this->getArmor()-armor_thing->getAdd_armor());
                this->setMax_hp(this->getMax_hp()-armor_thing->getAdd_hp());
                this->setArmor_thing(static_cast<Armor*>(eq[i]));
                this->setArmor(this->getArmor()+armor_thing->getAdd_armor());
                this->setMax_hp(this->getMax_hp()+armor_thing->getAdd_hp());
                eq[i]=temp;
            }

        }
        if(eq[i]->getTt()==usable){
            Usable* u= static_cast<Usable*>(eq[i]);

            if(this->hp+u->getReg_hp()>this->max_hp){
                this->hp=this->max_hp;
            }
            else{
                this->hp+=u->getReg_hp();
            }
            if(this->mana+u->getReg_mana()>this->max_mana){
                this->mana=this->max_mana;
            }
            else{
                this->mana+=u->getReg_mana();
            }
            if(this->stamina+u->getReg_stamina()>this->max_stamina){
                this->stamina=this->max_stamina;
            }
            else{
                this->stamina+=u->getReg_stamina();
            }
            eq.erase(eq.begin()+i);
        }
    }


}

void Character::putOff(Thing *th) {
    if(this->isIsalive()) {
        if (th->getTt() == weapon) {
            this->setDamage(this->getStrength());
            this->setAttackRange(this->getAttackRange() - wp->getRange());
            eq.push_back(th);
            this->setWeapon(nullptr);
        }
        if (th->getTt() == armor_type) {
            this->setArmor(this->getArmor()-this->armor_thing->getAdd_armor());
            this->setMax_hp(this->getMax_hp()-this->armor_thing->getAdd_hp());
            eq.push_back(th);
            this->setArmor_thing(nullptr);
        }
    }
}

void Character::add_to_eq(Thing *th) {
    if(this->isIsalive()){
        eq.push_back(th);
    }

}

void Character::drop_from_eq(int i) {
    if(this->isIsalive()){
        eq.erase(eq.begin()+i);
    }
}

void Character::lvl_up() {
    if(exp>=next_lvl_exp){
        lvl++;
        exp=exp-next_lvl_exp;
        next_lvl_exp=(next_lvl_exp*3)/2;
        this->setMax_hp(this->getMax_hp()+50*((lvl*5)/2));
        this->setMax_stamina(this->getMax_stamina()+50);
        ability_point++;
    }

}

int Character::getAbility_point() const {
    return ability_point;
}

void Character::setAbility_point(int ability_point) {
    Character::ability_point = ability_point;
}

const std::vector<Thing *> &Character::getEq() const {
    return eq;
}

void Character::setEq(const std::vector<Thing *> &eq) {
    Character::eq = eq;
}

void Character::add_exp(int ae) {
    this->exp+=ae;
    this->lvl_up();

}

void Character::improve_strength() {
    if(ability_point>0){
        this->setStrength(this->getStrength()+10);
        this->setDamage(this->getDamage()+10);
        ability_point--;
    }
}

void Character::improve_agility() {
    if(ability_point>0){
        this->setAgility(this->getAgility()+10);
        ability_point--;
    }
}

void Character::improve_intelligence() {
    if(ability_point>0){
        this->setIntelligence(this->getIntelligence()+10);
        ability_point--;
    }
}

Character::Character(int hp, int posX, int posY, const std::string &name, int attackRange,
                     int stamina, int max_hp, int max_stamina, int strength, int intelligence, int agility, int armor,
                     int damage, bool isalive, int mana, int max_mana, int exp, int next_lvl_exp, int lvl, int ability_point) :
        Creature(character, hp, posX, posY, name, attackRange, stamina, max_hp,
                                                                max_stamina, strength, intelligence, agility, armor,
                                                                damage, isalive), mana(mana), max_mana(max_mana), exp(exp),
                                                       next_lvl_exp(next_lvl_exp), lvl(lvl),
                                                       ability_point(ability_point), wp(nullptr), armor_thing(nullptr) {}

int Character::getMax_mana() const {
    return max_mana;
}

void Character::setMax_mana(int max_mana) {
    Character::max_mana = max_mana;
}

void Character::renew_Hp() {
    this->hp=this->max_hp;
}

void Character::renew_Stamina() {
    this->stamina=this->max_stamina;
}

void Character::renew_Mana() {
    this->mana=this->max_mana;

}





