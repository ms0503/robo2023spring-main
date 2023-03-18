//
// Created by ms0503 on 23/03/09.
//

#include "Thrower.hh"

Thrower::Thrower(Pin pin):
    LMLL::GPIO(pin, PinMode::OUTPUT) {
}

void Thrower::dispatch() const {
    high();
}

void Thrower::reload() const {
    low();
}
