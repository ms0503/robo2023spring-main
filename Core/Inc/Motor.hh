//
// Created by ms0503 on 23/03/07.
//

#ifndef MAIN_MOTOR_HH
#define MAIN_MOTOR_HH

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

/// モーターの最高速度
constexpr const int32_t MOTOR_SPEED_MAX = 30;

/// モーターの回転方向
enum class EnumMotorRotate : int8_t {
    LEFT = -1,
    RIGHT = 1
};

/// モーター制御クラス
class Motor {
public:
    Motor();
    ~Motor();
};

#endif //MAIN_MOTOR_HH
