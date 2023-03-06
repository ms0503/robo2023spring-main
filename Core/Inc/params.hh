//
// Created by ms0503 on 23/03/03.
//

#ifndef MAIN_PARAMS_HH
#define MAIN_PARAMS_HH

#include "types.hh"
#include <cstdint>
#include <map>
#include <string>

// Addresses
constexpr const uint8_t ADDR_MAIN = 0x00;
constexpr const uint8_t ADDR_MOTOR_FL = 0x10;
constexpr const uint8_t ADDR_MOTOR_FR = 0x11;
constexpr const uint8_t ADDR_MOTOR_RL = 0x12;
constexpr const uint8_t ADDR_MOTOR_RR = 0x13;

// Sizes
constexpr const uint16_t SBDBT_RECEIVE_SIZE = 8;

// Motor presets
constexpr const MotorPreset MOTOR_PRESET_NORMAL {
    .FL = -10,
    .FR = -10,
    .RL = 10,
    .RR = 10
};
constexpr const MotorPreset MOTOR_PRESET_STOP {
    .FL = 0,
    .FR = 0,
    .RL = 0,
    .RR = 0
};

#endif //MAIN_PARAMS_HH
