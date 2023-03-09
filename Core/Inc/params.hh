//
// Created by ms0503 on 23/03/03.
//

#ifndef MAIN_PARAMS_HH
#define MAIN_PARAMS_HH

#include "stm32f407xx.h"
#include <cstdint>

// Addresses
constexpr const uint8_t ADDR_MAIN = 0x00;
constexpr const uint8_t ADDR_MOTOR_FL = 0x10;
constexpr const uint8_t ADDR_MOTOR_FR = 0x11;
constexpr const uint8_t ADDR_MOTOR_RL = 0x12;
constexpr const uint8_t ADDR_MOTOR_RR = 0x13;

// Pins
constexpr const uint16_t PIN_AIR_CYLINDER_ARM = 0;
constexpr const uint16_t PIN_AIR_CYLINDER_THROWER = 1;

// Sizes
constexpr const uint16_t SBDBT_RECEIVE_SIZE = 8;

#endif //MAIN_PARAMS_HH
