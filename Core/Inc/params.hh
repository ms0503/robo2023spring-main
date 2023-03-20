//
// Created by ms0503 on 23/03/03.
//

#ifndef MAIN_PARAMS_HH
#define MAIN_PARAMS_HH

#include "Motor.hh"
#include "stm32f4xx_ll_gpio.h"
#include <cstdint>

namespace LM = LibMecha::v2;
namespace LMLL = LibMecha::v2::LowLayer;

// <editor-fold desc="CANアドレス">
/// メインボードのCANアドレス
constexpr const std::uint8_t ADDR_MAIN = 0x00;
/// ホイールのCANアドレス
constexpr const LM::Motor::Address ADDR_MOTOR = {
    .FL = 0x17,
    .FR = 0x11,
    .RL = 0x12,
    .RR = 0x13
};
// </editor-fold>

// <editor-fold desc="GPIOピン">
/// 表面実装のLED
const LMLL::GPIO::Pin PIN_LED_1 = {
    .gpio = GPIOC,
    .pin = LL_GPIO_PIN_12
};
/// 表面実装のLED
const LMLL::GPIO::Pin PIN_LED_2 = {
    .gpio = GPIOC,
    .pin = LL_GPIO_PIN_13
};
/// 表面実装のLED
const LMLL::GPIO::Pin PIN_LED_3 = {
    .gpio = GPIOC,
    .pin = LL_GPIO_PIN_14
};
/// 表面実装のLED
const LMLL::GPIO::Pin PIN_LED_4 = {
    .gpio = GPIOC,
    .pin = LL_GPIO_PIN_15
};
/// 回収用アーム
const LMLL::GPIO::Pin PIN_ARM = {
    .gpio = GPIOE,
    .pin = LL_GPIO_PIN_0
};
/// 射出機構
const LMLL::GPIO::Pin PIN_THROWER = {
    .gpio = GPIOE,
    .pin = LL_GPIO_PIN_1
};
// </editor-fold>

// <editor-fold desc="モーターパラメータ">
/// モーターの最高速度
constexpr const std::int32_t MOTOR_SPEED_MAX = 30;
// </editor-fold>

#endif//MAIN_PARAMS_HH
