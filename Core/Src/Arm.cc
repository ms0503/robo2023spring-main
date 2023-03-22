//
// Created by ms0503 on 23/03/09.
//

#include "Arm.hh"

void Arm::close() const {
    high(HAND_INDEX);
}

void Arm::open() const {
    low(HAND_INDEX);
}

void Arm::move() const {
    high(MOVER_LEFT_INDEX);
    high(MOVER_RIGHT_INDEX);
}

void Arm::back() const {
    low(MOVER_LEFT_INDEX);
    low(MOVER_RIGHT_INDEX);
}
