//
// Created by kejbi on 28.05.18.
//

#include "goblin.h"


Goblin::Goblin(int posX, int posY) : Mob(70, posX, posY, "goblin", 1, 100, 70, 100, 10,
                                    10, 10, 15, 25, true, 50) {}

Goblin::Goblin(int hp, int posX, int posY, const std::string &name, int attackRange, int stamina, int max_hp,
               int max_stamina, int strength, int intelligence, int agility, int armor, int damage, bool isalive,
               int exp_given) : Mob(hp, posX, posY, name, attackRange, stamina, max_hp, max_stamina, strength,
                                    intelligence, agility, armor, damage, isalive, exp_given) {}
