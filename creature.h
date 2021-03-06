//
// Created by kejbi on 10.05.18.
//

#ifndef RPG_CREATURE_H
#define RPG_CREATURE_H

#include <iostream>

//abstract class of creature objects(players, mobs, etc)
enum creature_type{
    character,
    mob
};
class Creature{
protected:
    creature_type ct; //type of creature character or mob, used to distinguish character and mob
    int hp; //health points of creature
    int posX; //actual X position on map
    int posY; //actual Y position on map
    std::string name; //name of creature
    int attackRange; //range of attack (distance on which you can damage other creature)
    int stamina; //every single activity reduces it, your range of activity, every turn it regenerates
    int max_hp; //max health points, you can't regenerate more that this
    int max_stamina;// max stamina points ----------||----------
    int strength; //strength of creature (used in damage, skills)
    int intelligence; //intelligence of creature (used in skills)
    int agility; //agility of creature (used to counter attack)
    int armor; //armor reduced damage recieved
    int damage; //damage inflicted
    bool isalive; //true when alive, false when dead
public:
    //getters and setters
    creature_type getCt() const;

    void setCt(creature_type ct);

    int getDamage() const;

    void setDamage(int damage);

    bool isIsalive() const;

    void setIsalive(bool isalive);

    int getMax_hp() const;

    void setMax_hp(int max_hp);

    int getMax_stamina() const;

    void setMax_stamina(int max_stamina);

    int getStamina() const;

    void setStamina(int stamina);

    int getAttackRange() const;

    void setAttackRange(int attackRange);

    void setHp(int hp);

    void setPosX(int posX);

    void setPosY(int posY);

    void setName(const std::string &name);

    int getPosX() const;

    int getPosY() const;

    const std::string &getName() const;

    int getHp() const;

    int getStrength() const;

    void setStrength(int strength);

    int getIntelligence() const;

    void setIntelligence(int intelligence);

    int getAgility() const;

    void setAgility(int agility);

    int getArmor() const;

    void setArmor(int armor);


    Creature(creature_type ct, int hp, int posX, int posY, const std::string &name, int attackRange, int stamina,
             int max_hp, int max_stamina, int strength, int intelligence, int agility, int armor, int damage,
             bool isalive);


    //functions


    //x, y destination of move
    //1 distance unit costs 10 stamina
    //false when not enough stamina or creature is dead
    bool move(int x, int y);

    //returns distance beetwen this creature and (x,y)
    //for example (0,0) and (0,1) are 1 distance unit distant
    int distance(int x, int y);


    // virtual functions

    //mobs and characters has different attack (mob's attack can't be countered, mobs doesn't recieve exp etc)
    virtual bool attack(Creature &cre)=0;


};
#endif //RPG_CREATURE_H
