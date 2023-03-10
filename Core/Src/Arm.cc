//
// Created by ms0503 on 23/03/09.
//

#include "Arm.hh"
#include "params.hh"
#include "stm32f4xx_hal.h"

Arm::Arm() = default;

Arm::~Arm() = default;

void Arm::close() {
    HAL_GPIO_WritePin(GPIOA, PIN_ARM, GPIO_PIN_SET);
}

void Arm::open() {
    HAL_GPIO_WritePin(GPIOA, PIN_ARM, GPIO_PIN_RESET);
}
