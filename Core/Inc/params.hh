//
// Created by ms0503 on 23/03/03.
//

#ifndef MAIN_PARAMS_HH
#define MAIN_PARAMS_HH

#include "Motor.hh"
#include "stm32f407xx.h"
#include <cstdint>

using namespace LibMecha::v1;

// <editor-fold desc="CANアドレス">
/// メインボードのCANアドレス
constexpr const uint8_t ADDR_MAIN = 0x00;
/// ホイールのCANアドレス
constexpr const MotorAddress ADDR_MOTOR = {
    .FL = 0x10,
    .FR = 0x11,
    .RL = 0x12,
    .RR = 0x13
};
// </editor-fold>

// <editor-fold desc="GPIOピン">
/// 回収機構のピン
constexpr const uint16_t PIN_ARM = 0;
/// 射出機構のピン
constexpr const uint16_t PIN_THROWER = 1;
// </editor-fold>

// <editor-fold desc="データサイズ">
/// SBDBTのデータサイズ
constexpr const uint16_t SBDBT_RECEIVE_SIZE = 8;
// </editor-fold>

// <editor-fold desc="その他パラメータ">
/// モーターの最高速度
constexpr const int32_t MOTOR_SPEED_MAX = 30;
// </editor-fold>

#endif //MAIN_PARAMS_HH
