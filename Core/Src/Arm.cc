//
// Created by ms0503 on 23/03/09.
//

#include "Arm.hh"

Arm::Arm(const std::vector<Pin> &pin):
    GPIO(pin) {
    //_state.at(HAND_INDEX) = PinState::LOW;
    //_state.at(MOVER_LEFT_INDEX) = PinState::LOW;
    //_state.at(MOVER_RIGHT_INDEX) = PinState::LOW;
    _state.assign({ PinState::LOW,
                    PinState::LOW,
                    PinState::LOW });
}
