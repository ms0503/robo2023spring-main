//
// Created by ms0503 on 23/03/08.
//

#include "Controller.hh"
#include "Motor.hh"
#include <cmath>
#include <map>
#include <string>

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
    const StickTheta theta = sticksToTheta(leftX, leftY, rightX, rightY);
    const long double leftR = sqrtl(leftX * leftX + leftY * leftY);
    const long double rightR = sqrtl(rightX * rightX + rightY * rightY);
    return {
        .FL = static_cast<int32_t>(sinl(theta.left - (M_PI / 8)) * static_cast<int8_t>(EnumMotorRotate::LEFT) * leftR),
        .FR = static_cast<int32_t>(sinl(theta.left + (M_PI / 8)) * static_cast<int8_t>(EnumMotorRotate::RIGHT) * leftR),
        .RL = static_cast<int32_t>(sinl(theta.left + (M_PI / 8)) * static_cast<int8_t>(EnumMotorRotate::RIGHT) * leftR),
        .RR = static_cast<int32_t>(sinl(theta.left - (M_PI / 8)) * static_cast<int8_t>(EnumMotorRotate::LEFT) * leftR)
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
