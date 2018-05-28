//
// Created by kejbi on 28.05.18.
//

#include "barbarian.h"

Barbarian::Barbarian(int posX, int posY, const std::string &name) : Character(100, posX, posY, name,
                                                                                                  1, 100,
                                                                                                  100, 100,
                                                                                                  30,
                                                                                                  0, 10,
                                                                                                  0, 30,
                                                                                                  true, 50, 0,
                                                                                                  200, 1,
                                                                                                  0) {}

Barbarian::Barbarian(int hp, int posX, int posY, const std::string &name, int attackRange, int stamina, int max_hp,
                     int max_stamina, int strength, int intelligence, int agility, int armor, int damage, bool isalive,
                     int mana, int exp, int next_lvl_exp, int lvl, int ability_point) : Character(hp, posX, posY, name,
                                                                                                  attackRange, stamina,
                                                                                                  max_hp, max_stamina,
                                                                                                  strength,
                                                                                                  intelligence, agility,
                                                                                                  armor, damage,
                                                                                                  isalive, mana, exp,
                                                                                                  next_lvl_exp, lvl,
                                                                                                  ability_point) {}
