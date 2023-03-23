//
// Created by ms0503 on 23/03/03.
//

#ifndef MAIN_PARAMS_HH
#define MAIN_PARAMS_HH

#include "Motor.hh"
#include "stm32f4xx_ll_gpio.h"
#include "types.hh"
#include <cstdint>

namespace LM = LibMecha;
namespace LMLL = LibMecha::LowLayer;

// <editor-fold desc="CANアドレス">
/// メインボードのCANアドレス
constexpr const std::uint8_t ADDR_MAIN = 0x00;
/// ホイールのCANアドレス
constexpr const MotorAddress ADDR_MOTOR = {
    .FR = 0x14,
    .FL = 0x15,
    .RL = 0x16,
    .RR = 0x17
};
/*
constexpr const MotorAddress ADDR_MOTOR = {
    .FR = 0x10,
    .FL = 0x13,
    .RL = 0x12,
    .RR = 0x11
};
 */
// </editor-fold>

// <editor-fold desc="GPIOピン">
/// 表面実装のLED
const LMLL::GPIO::Pin PIN_LED_1 = {
    .gpio = GPIOC,
    .pin = LL_GPIO_PIN_12,
    .mode = LMLL::GPIO::PinMode::OUTPUT
};
/// 表面実装のLED
const LMLL::GPIO::Pin PIN_LED_2 = {
    .gpio = GPIOC,
    .pin = LL_GPIO_PIN_13,
    .mode = LMLL::GPIO::PinMode::OUTPUT
};
/// 表面実装のLED
const LMLL::GPIO::Pin PIN_LED_3 = {
    .gpio = GPIOC,
    .pin = LL_GPIO_PIN_14,
    .mode = LMLL::GPIO::PinMode::OUTPUT
};
/// 表面実装のLED
const LMLL::GPIO::Pin PIN_LED_4 = {
    .gpio = GPIOC,
    .pin = LL_GPIO_PIN_15,
    .mode = LMLL::GPIO::PinMode::OUTPUT
};
/// 回収用アーム - 把持部分
const LMLL::GPIO::Pin PIN_ARM_HAND = {
    .gpio = GPIOE,
    .pin = LL_GPIO_PIN_0,
    .mode = LMLL::GPIO::PinMode::OUTPUT
};
/// 回収用アーム - 移送部分左
const LMLL::GPIO::Pin PIN_ARM_MOVER_LEFT = {
    .gpio = GPIOE,
    .pin = LL_GPIO_PIN_1,
    .mode = LMLL::GPIO::PinMode::OUTPUT
};
/// 回収用アーム - 移送部分右
const LMLL::GPIO::Pin PIN_ARM_MOVER_RIGHT = {
    .gpio = GPIOE,
    .pin = LL_GPIO_PIN_2,
    .mode = LMLL::GPIO::PinMode::OUTPUT
};
/// 射出機構 - ロック機構
const LMLL::GPIO::Pin PIN_THROWER_LOCKER = {
    .gpio = GPIOE,
    .pin = LL_GPIO_PIN_3,
    .mode = LMLL::GPIO::PinMode::OUTPUT
};
/// 射出機構 - ローダー左
const LMLL::GPIO::Pin PIN_THROWER_LOADER_LEFT = {
    .gpio = GPIOE,
    .pin = LL_GPIO_PIN_4,
    .mode = LMLL::GPIO::PinMode::OUTPUT
};
/// 射出機構 - ローダー右
const LMLL::GPIO::Pin PIN_THROWER_LOADER_RIGHT = {
    .gpio = GPIOE,
    .pin = LL_GPIO_PIN_5,
    .mode = LMLL::GPIO::PinMode::OUTPUT
};
// </editor-fold>

// <editor-fold desc="モーターパラメータ">
/// モーターの最高速度
constexpr const std::int32_t MOTOR_SPEED_MAX = 60;
// </editor-fold>

// <editor-fold desc="コントローラーパラメータ">
/// 左スティック横軸のデッドゾーン
constexpr const std::int32_t CTRL_DEAD_ZONE_LX = 16;
/// 左スティック縦軸のモーターのデッドゾーン
constexpr const std::int32_t CTRL_DEAD_ZONE_LY = 16;
/// 右スティック横軸のモーターのデッドゾーン
constexpr const std::int32_t CTRL_DEAD_ZONE_RX = 16;
/// 右スティック縦軸のモーターのデッドゾーン
constexpr const std::int32_t CTRL_DEAD_ZONE_RY = 16;
constexpr const std::array<std::int32_t, 4> CTRL_DEAD_ZONES {
    CTRL_DEAD_ZONE_LX,
    CTRL_DEAD_ZONE_LY,
    CTRL_DEAD_ZONE_RX,
    CTRL_DEAD_ZONE_RY
};
// </editor-fold>

#endif // MAIN_PARAMS_HH
