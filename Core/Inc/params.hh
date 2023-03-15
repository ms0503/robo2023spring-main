//
// Created by ms0503 on 23/03/03.
//

#ifndef MAIN_PARAMS_HH
#define MAIN_PARAMS_HH

#include "Motor.hh"
#include "stm32f407xx.h"
#include <cstdint>

namespace LM = LibMecha::v2;

// <editor-fold desc="CANアドレス">
/// メインボードのCANアドレス
constexpr const uint8_t ADDR_MAIN = 0x00;
/// ホイールのCANアドレス
constexpr const LM::Motor::Address ADDR_MOTOR = {
    .FL = 0x10,
    .FR = 0x11,
    .RL = 0x12,
    .RR = 0x13};
// </editor-fold>

// <editor-fold desc="GPIOピン">
/// 回収機構のピン
constexpr const uint16_t PIN_ARM = 2;
/// 射出機構のピン
constexpr const uint16_t PIN_THROWER = 3;
// </editor-fold>

// <editor-fold desc="モーターパラメータ">
/// モーターの最高速度
constexpr const int32_t MOTOR_SPEED_MAX = 30;
// </editor-fold>

#endif//MAIN_PARAMS_HH
