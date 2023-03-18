//
// Created by ms0503 on 23/03/09.
//

#include "Arm.hh"

Arm::Arm(const Pin pin):
    LMLL::GPIO(pin, PinMode::OUTPUT) {
}

void Arm::close() const {
    high();
}

void Arm::open() const {
    low();
}
