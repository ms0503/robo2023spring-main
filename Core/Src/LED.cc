//
// Created by ms0503 on 23/03/18.
//

#include "LED.hh"

LED::LED(const Pin pin):
    LMLL::GPIO(pin, PinMode::OUTPUT) {
}

void LED::turnOff() const {
    low();
}

void LED::turnOn() const {
    high();
}
