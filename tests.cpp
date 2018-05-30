//
// Created by kejbi on 22.05.18.
//

#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "creature.h"
#include "thing.h"
#include "sword.h"
#include "character.h"
#include "mana_potion.h"
#include "barbarian.h"
#include "goblin.h"
#include "hauberk.h"


TEST_CASE("Attack test"){
    Barbarian b(0,0,"barb");
    Goblin g(0,1);
    b.attack(g);
    REQUIRE(g.getHp()!=70);
    g.attack(b);
    REQUIRE(b.getHp()!=b.getMax_hp());
}
TEST_CASE("Death, exp, lvlup"){
    Barbarian b(100,0,0,"barb",1,100,100,100,1000,0,100,1000,1000,true,0,100,90,100,1,0);
    Goblin g(0,1);
    b.attack(g);
    REQUIRE(b.getLvl()==2);
    REQUIRE(g.isIsalive()==false);
    b.improve_strength();
    REQUIRE(b.getAbility_point()==0);
    REQUIRE(b.getStrength()==1010);
    REQUIRE(b.getDamage()==1010);
}
TEST_CASE("Weapon, armor"){
    Barbarian b(0,0,"barb");
    Sword swordie;
    Sword* s= &swordie;
    Hauberk hauberkie;
    Hauberk* h= &hauberkie;
    b.add_to_eq(s);
    b.add_to_eq(h);
    b.use(0);
    b.use(0);
    REQUIRE(b.getDamage()==80);
    REQUIRE(b.getArmor()==10);
    REQUIRE(b.getEq().size()==0);
    b.putOff(s);
    REQUIRE(b.getDamage()==b.getStrength());
    REQUIRE(b.getEq().size()==1);
    b.putOff(h);
    REQUIRE(b.getArmor()==0);

}
TEST_CASE("Barbarian skills"){
    Barbarian b1(0,0,"barb");
    Barbarian b2(2,1,"barbie");
    b1.charge(b2,0,1);
    REQUIRE(b1.getPosY()==1);
    REQUIRE(b1.getMana()!=b1.getMax_mana());
    REQUIRE(b2.getHp()==b2.getMax_hp());
    b1.renew_Mana();
    b1.renew_Stamina();
    b1.charge(b2,2,2);
    REQUIRE(b2.getHp()==70);
    REQUIRE(b1.getHp()==49);

}