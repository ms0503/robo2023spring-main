//
// Created by ms0503 on 23/03/07.
//

#ifndef MAIN_MOTOR_HH
#define MAIN_MOTOR_HH

#include "MotorDriver.hpp"
#include "params.hh"
#include <cstdint>
#include <map>
#include <string>

/// モーター信号
typedef struct {
    /// 左前方
    int32_t FL;
    /// 右前方
    int32_t FR;
    /// 左後方
    int32_t RL;
    /// 右後方
    int32_t RR;
} MotorState;

/// モーター
enum class EnumMotor : uint8_t {
    FL = ADDR_MOTOR_FL,
    FR = ADDR_MOTOR_FR,
    RL = ADDR_MOTOR_RL,
    RR = ADDR_MOTOR_RR
};

/// モーターの回転方向
enum class EnumMotorRotate : int8_t {
    LEFT = -1,
    RIGHT = 1
};

/// モーター制御クラス
class Motor {
public:
    explicit Motor(const MotorDriver &md);
    ~Motor();
    void update(MotorState state);

private:
    MotorDriver _md;
};

#endif //MAIN_MOTOR_HH
