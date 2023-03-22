//
// Created by ms0503 on 23/03/09.
//

#include "Thrower.hh"

void Thrower::dispatch() const {
    low(LOADER_LEFT_INDEX);
    low(LOADER_RIGHT_INDEX);
}

void Thrower::reload() const {
    high(LOADER_LEFT_INDEX);
    high(LOADER_RIGHT_INDEX);
}

void Thrower::lock() const {
    high(LOCKER_INDEX);
}

void Thrower::unlock() const {
    low(LOCKER_INDEX);
}
