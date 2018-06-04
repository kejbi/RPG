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
#include "knight.h"
#include "hunter.h"
#include "bow.h"
#include "stamina_potion.h"
#include "hp_potion.h"


TEST_CASE("Attack test"){
    Barbarian b(0,0,"barb");
    Goblin g(0,1);
    b.attack(g);
    REQUIRE(g.getHp()!=70); //reduced hp after attack
    g.attack(b);
    REQUIRE(b.getHp()!=b.getMax_hp()); //reduced hp after attack
}
TEST_CASE("Death, exp, lvlup"){
    Barbarian b(100,0,0,"barb",1,100,100,100,1000,0,100,1000,1000,true,0,100,90,100,1,0);
    Goblin g(0,1);
    b.attack(g);
    REQUIRE(b.getLvl()==2); //goblin died, so experiance was increased and barbarian leveled up
    REQUIRE(g.isIsalive()==false); //goblin died
    b.improve_strength(); // lvl up gives ability point and we can improve some facilities, here strength
    REQUIRE(b.getAbility_point()==0); //used
    REQUIRE(b.getStrength()==1010); //strength increased  by 10
    REQUIRE(b.getDamage()==1010); //damage increased by 10, after improving strength
}
TEST_CASE("Weapon, armor"){
    Barbarian b(0,0,"barb");
    Sword swordie;
    Sword* s= &swordie;
    Hauberk hauberkie;
    Hauberk* h= &hauberkie;
    // adding to eq and wearing weapon and armor
    b.add_to_eq(s);
    b.add_to_eq(h);
    b.use(0);
    b.use(0);
    REQUIRE(b.getDamage()==80); //damage increased by 50
    REQUIRE(b.getArmor()==10); //armor increased by 10
    REQUIRE(b.getEq().size()==0); //empty eq
    b.putOff(s); //put off sword
    REQUIRE(b.getDamage()==b.getStrength()); //reduced damage
    REQUIRE(b.getEq().size()==1); //sword returned to eq
    b.putOff(h);
    REQUIRE(b.getArmor()==0);

}
TEST_CASE("Barbarian skills"){
    Barbarian b1(0,0,"barb");
    Barbarian b2(2,1,"barbie");
    REQUIRE(b1.stone_throw(b2)==false); //not in range
    REQUIRE(b2.getHp()==b2.getMax_hp());//no damage done, not in range
    REQUIRE(b1.getHp()==b1.getMax_hp());//no self damage, because no damage done
    b1.charge(b2,0,1);
    REQUIRE(b1.getPosY()==1); //position changed
    REQUIRE(b1.getMana()!=b1.getMax_mana()); //reduced mana
    REQUIRE(b2.getHp()==b2.getMax_hp());//no damage done, not in range
    REQUIRE(b1.getHp()==b1.getMax_hp());//no self damage, because no damage done
    b1.renew_Mana();
    b1.renew_Stamina();
    b1.charge(b2,2,2);
    REQUIRE(b2.getHp()==70); //damage done, 30 reduced
    REQUIRE(b1.getHp()==49); //self damage, 51 reduced
    b1.renew_Stamina();
    b1.move(0,1);
    b1.stone_throw(b2);
    REQUIRE(b2.getHp()==55); //damage done, 15 reduced

}
TEST_CASE("Knight skills"){
    Knight k1(0,0,"knite");
    Knight k2(0,2,"knitie");
    REQUIRE(k1.precise_cut(k2)==false); //not in range
    k1.move(0,1);
    REQUIRE(k1.precise_cut(k2)==true); //in range
    REQUIRE(k2.getHp()==72); // armor reduced to zero + added damage 8
    Hauberk h;
    Hauberk* hb=&h;
    k2.add_to_eq(hb);//added to eq hauberk
    k2.use(0); // wear hauberk, increase armor
    k1.precise_cut(k2);
    REQUIRE(k2.getHp()==49); //again armor reduced to zero + 3 added damage
    k1.smart_choice();
    REQUIRE(k1.getHp()==100); //nothing added
    REQUIRE(k1.getMana()==80); // 30 mana added, 10 reduced for using that skill, in result 20 more
    k2.smart_choice();
    REQUIRE(k2.getHp()==79);
    REQUIRE(k2.getMana()==100);
}
TEST_CASE("Hunter skills"){
    Hunter h1(0,0,"huntie");
    Goblin g(4,3);
    Bow b;
    Bow* bw=&b;
    h1.add_to_eq(bw);
    h1.use(0);
    REQUIRE(h1.getAttackRange()==6);
    REQUIRE(h1.get_out_of_my_face(g)==false); //out of range, distance is 7, range is 6
    g.move(2,3); //getting in range
    h1.get_out_of_my_face(g);
    REQUIRE(g.getPosX()==4); //moved
    REQUIRE(g.getPosY()==5);
    REQUIRE(g.getHp()==40); //reduced hp because of damage done
    g.move(2,3);
    h1.attack(g);
    h1.mob_executer(g); // goblin died, hunter gets 2x more exp; (2+lvl/5) here 1/5=0
    REQUIRE(h1.getExp()==100); //goblin gives 50 exp, so our huntie has 2x more

}

TEST_CASE("Counters"){
    Barbarian b1(100,0,0,"barb",1,1000,100,1000,30,0,1000,0,30,true,0,0,0,100,1,0); //1000 agility gives 100% chance for counter
    Hunter h1(100,0,1,"huntie",1,1000,100,1000,30,0,1000,0,30,true,0,0,0,100,1,0);
    b1.attack(h1);
    REQUIRE(b1.getHp()==70); //reduced hp after counter
    REQUIRE(h1.getHp()==70); //reduced hp after attack
    h1.move(0,2);
    h1.setAttackRange(2);
    h1.attack(b1);
    REQUIRE(b1.getHp()==40); //reduced hp after attack
    REQUIRE(h1.getHp()==70); //h1 wasn't in range of b1, so there was no counter
    b1.setHp(10);
    b1.move(0,1); // b1 again in range of h1
    h1.attack(b1);
    REQUIRE(b1.isIsalive()==false); //b1 died
    REQUIRE(h1.getHp()==70); //h1 didn't recive any damage from counter because b1 was already dead
    b1.revive(); // revive of b1
    REQUIRE(b1.isIsalive());
    b1.setHp(10);
    b1.attack(h1);
    REQUIRE(h1.getHp()==40); //reduced hp after attack
    REQUIRE(b1.isIsalive()==false); //b1 died from counter of h1

}
TEST_CASE("Usables"){
    Barbarian b1(50,0,0,"barb",1,20,100,50,30,0,1000,0,30,true,20,100,0,100,1,0);
    ManaPotion p1;
    ManaPotion* wp1 = &p1;
    StaminaPotion p2;
    StaminaPotion* wp2 = &p2;
    HpPotion p3;
    HpPotion* wp3 = &p3;
    b1.add_to_eq(wp1);
    b1.add_to_eq(wp2);
    b1.add_to_eq(wp3);
    b1.use(2); //hp potion used
    REQUIRE(b1.getHp()==90);
    b1.use(0);//mana potion used
    REQUIRE(b1.getMana()==40);
    b1.use(0); //stamina potion used
    REQUIRE(b1.getStamina()==35);
    b1.add_to_eq(wp3);
    b1.use(0); //again used hp potion
    REQUIRE(b1.getHp()==100); //hp is equal 100 not 130 (100 is max_hp)

}

TEST_CASE("stamina, mana, alive"){
    Knight k1(0,0,"knite");
    Barbarian b1(0,1,"barb");
    Hunter h1(0,2,"huntie");
    Goblin g(0,3);
    HpPotion p1;
    HpPotion* wp1=&p1;
    REQUIRE(k1.move(0,11)==false); //required 110 stamina, knite has only 100, cant to that
    k1.setMana(10);
    REQUIRE(k1.precise_cut(b1)==false); //no mana required
    k1.setStamina(5);
    REQUIRE(k1.attack(b1)==false); //no stamina required to attack
    k1.renew_Stamina();
    k1.renew_Hp();
    k1.renew_Mana();
    k1.setIsalive(false);
    //dead can't do anything
    REQUIRE(k1.move(0,2)==false);
    REQUIRE(k1.attack(b1)==false);
    k1.add_to_eq(wp1);
    k1.setHp(50);
    k1.use(1);
    REQUIRE(k1.getHp()==50);
    k1.setIsalive(true);
    b1.setIsalive(false);
    REQUIRE(b1.charge(k1,0,1)==false);
    REQUIRE(b1.stone_throw(k1)==false);
    h1.setIsalive(false);
    REQUIRE(h1.mob_executer(g)==false);
    REQUIRE(h1.get_out_of_my_face(g)==false);
}