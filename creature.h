//
// Created by kejbi on 10.05.18.
//

#ifndef RPG_CREATURE_H
#define RPG_CREATURE_H

#include <iostream>

//abstract class of creature objects(players, mobs, etc)
class Creature{
private:
    int hp; //health points of creature
    int posX; //actual X position on map
    int posY; //actual Y position on map
    std::string name; //name of creature
    int attackRange; //range of attack (distance on which you can damage other creature)
    int stamina; //every single activity reduces it, your range of activity, every turn it regenerates
    int max_hp; //max health points, you can't regenerate more that this
    int max_stamina;// max stamina points ----------||----------

public:
    //getters and setters

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

    //functions
    bool move(int x, int y);

    int distance(int x, int y);


    // virtual functions

    virtual bool attack(Creature &cre)=0;

    virtual bool counter(Creature &cre)=0;


};
#endif //RPG_CREATURE_H
