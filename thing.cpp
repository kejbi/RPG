//
// Created by kejbi on 22.05.18.
//

#include "thing.h"

thing_type Thing::getTt() const {
    return tt;
}

void Thing::setTt(thing_type tt) {
    Thing::tt = tt;
}

Thing::Thing(thing_type tt) : tt(tt) {}
