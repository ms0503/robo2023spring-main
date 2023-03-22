//
// Created by ms0503 on 23/03/18.
//

#include "LED.hh"

void LED::turnOff(const std::size_t index) const {
    low(index);
}

void LED::turnOn(const std::size_t index) const {
    high(index);
}
