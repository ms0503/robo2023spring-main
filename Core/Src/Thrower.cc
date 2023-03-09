//
// Created by ms0503 on 23/03/09.
//

#include "Thrower.hh"
#include "params.hh"
#include "stm32f4xx_hal.h"

Thrower::Thrower() = default;

Thrower::~Thrower() = default;

void Thrower::dispatch() {
    HAL_GPIO_WritePin(GPIOA, PIN_AIR_CYLINDER_THROWER, GPIO_PIN_SET);
}

void Thrower::reload() {
    HAL_GPIO_WritePin(GPIOA, PIN_AIR_CYLINDER_THROWER, GPIO_PIN_RESET);
}
