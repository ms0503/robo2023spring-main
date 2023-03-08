//
// Created by ms0503 on 23/03/07.
//

#ifndef MAIN_MOTOR_HH
#define MAIN_MOTOR_HH

#include <cstdint>
#include <map>
#include <string>

typedef struct {
    int32_t FL;
    int32_t FR;
    int32_t RL;
    int32_t RR;
} MotorState;

constexpr const int32_t MOTOR_SPEED_MAX = 30;

enum class EnumMotorRotate : int8_t {
    LEFT = -1,
    RIGHT = 1
};

class Motor {
public:
    Motor();
    ~Motor();
    static void rotate(int32_t speed);
};

#endif //MAIN_MOTOR_HH
