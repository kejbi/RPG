//
// Created by kejbi on 22.05.18.
//

#ifndef RPG_THING_H
#define RPG_THING_H
enum thing_type{
    weapon,
    armor_type,
    usable
};

//things can be stored by character, character can use them
//things modify character statistics
class Thing{
private:
    thing_type tt; // type of thing (used to distinguish type of thing, when thing is used (different behaviours for every type))
public:
    Thing(thing_type tt);

    thing_type getTt() const;

    void setTt(thing_type tt);
};
#endif //RPG_THING_H
