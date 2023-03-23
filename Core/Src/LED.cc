//
// Created by ms0503 on 23/03/18.
//

#include "LED.hh"

LED::LED(const Pin pin):
    GPIO({ pin }) {
    _state.at(0) = PinState::LOW;
}
