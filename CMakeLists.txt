cmake_minimum_required(VERSION 3.9)
project(RPG)

set(CMAKE_CXX_STANDARD 11)

add_executable(RPG creature.cpp creature.h character.cpp character.h catch.h tests.cpp thing.cpp thing.h weapon.cpp weapon.h armor.cpp armor.h usable.cpp usable.h bow.cpp bow.h sword.cpp sword.h mana_potion.cpp mana_potion.h hp_potion.cpp hp_potion.h stamina_potion.cpp stamina_potion.h hauberk.cpp hauberk.h leather_armor.cpp leather_armor.h barbarian.cpp barbarian.h mob.cpp mob.h goblin.cpp goblin.h)