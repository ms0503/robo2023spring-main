//
// Created by ms0503 on 23/03/03.
//

#ifndef MAIN_PARAMS_HH
#define MAIN_PARAMS_HH

#include "Motor.hh"
#include "stm32f4xx_ll_gpio.h"
#include "types.hh"
#include <cstdint>

namespace LM = LibMecha::v2;
namespace LMLL = LibMecha::v2::LowLayer;

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
constexpr const std::int32_t CTRL_DEAD_ZONES[4] {
    CTRL_DEAD_ZONE_LX,
    CTRL_DEAD_ZONE_LY,
    CTRL_DEAD_ZONE_RX,
    CTRL_DEAD_ZONE_RY
};
// </editor-fold>

#endif //MAIN_PARAMS_HH
