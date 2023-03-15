//
// Created by ms0503 on 23/03/09.
//

#include "Arm.hh"
#include "params.hh"
#include "stm32f4xx_ll_gpio.h"

Arm::Arm() = default;

Arm::~Arm() = default;

void Arm::close() {
    LL_GPIO_SetOutputPin(GPIOE, PIN_ARM);
}

void Arm::open() {
    LL_GPIO_ResetOutputPin(GPIOE, PIN_ARM);
}
