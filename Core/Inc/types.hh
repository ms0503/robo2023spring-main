//
// Created by ms0503 on 23/03/05.
//

#ifndef MAIN_TYPES_HH
#define MAIN_TYPES_HH

#include <cstdint>

struct MotorAddress {
    std::uint8_t FR;
    std::uint8_t FL;
    std::uint8_t RL;
    std::uint8_t RR;
};

#endif // MAIN_TYPES_HH
