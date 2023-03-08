//
// Created by ms0503 on 23/03/08.
//

#include "Controller.hh"
#include "Motor.hh"
#include <cmath>
#include <map>

const std::map<EnumMotor, int8_t> Controller::DEAD_ZONES = {
    {
        EnumMotor::FL,
        0
    },
    {
        EnumMotor::FR,
        0
    },
    {
        EnumMotor::RL,
        0
    },
    {
        EnumMotor::RR,
        0
    }
};

Controller::Controller() = default;

Controller::~Controller() = default;

MotorState Controller::stickToMotor(const int8_t leftX, const int8_t leftY, const int8_t rightX, const int8_t rightY) {
    const long double FL = 3. / 8 * M_PI;
    const long double FR = 1. / 8 * M_PI;
    const long double RL = 5. / 8 * M_PI;
    const long double RR = 7. / 8 * M_PI;
    const StickTheta theta = sticksToTheta(leftX, leftY, rightX, rightY);
    const long double powerFL = sinl(theta.left + FL) * MOTOR_SPEED_MAX;
    const long double powerFR = sinl(theta.left + FR) * MOTOR_SPEED_MAX;
    const long double powerRL = sinl(theta.left + RL) * MOTOR_SPEED_MAX;
    const long double powerRR = sinl(theta.left + RR) * MOTOR_SPEED_MAX;
    const long double powerMax = fmaxl(fmaxl(fmaxl(fabsl(powerFL), fabsl(powerFR)), fabsl(powerRL)), fabsl(powerRR));
    return {
        .FL = static_cast<int32_t>(powerFL * powerMax),
        .FR = static_cast<int32_t>(powerFR * powerMax),
        .RL = static_cast<int32_t>(powerRL * powerMax),
        .RR = static_cast<int32_t>(powerRR * powerMax)
    };
}

long double Controller::stickToTheta(const int8_t x, const int8_t y) {
    return atanl(static_cast<float>(y) / static_cast<float>(x));
}

StickTheta Controller::sticksToTheta(const int8_t leftX, const int8_t leftY, const int8_t rightX, const int8_t rightY) {
    return {
        .left = stickToTheta(leftX, leftY),
        .right = stickToTheta(rightX, rightY)
    };
}
