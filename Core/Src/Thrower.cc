//
// Created by ms0503 on 23/03/09.
//

#include "Thrower.hh"

Thrower::Thrower(const std::vector<Pin> &pin):
    GPIO(pin) {
    _state.at(LOADER_LEFT_INDEX) = PinState::LOW;
    _state.at(LOADER_RIGHT_INDEX) = PinState::LOW;
    _state.at(LOCKER_INDEX) = PinState::HIGH;
}
