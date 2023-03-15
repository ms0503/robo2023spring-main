//
// Created by ms0503 on 23/03/09.
//

#include "Thrower.hh"
#include "params.hh"
#include "stm32f4xx_ll_gpio.h"

Thrower::Thrower() = default;

Thrower::~Thrower() = default;

void Thrower::dispatch() {
    LL_GPIO_SetOutputPin(GPIOE, PIN_THROWER);
}

void Thrower::reload() {
    LL_GPIO_ResetOutputPin(GPIOE, PIN_THROWER);
}
