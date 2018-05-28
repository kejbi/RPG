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
class Thing{
private:
    thing_type tt;
public:
    Thing(thing_type tt);

    thing_type getTt() const;

    void setTt(thing_type tt);
};
#endif //RPG_THING_H
