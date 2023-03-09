//
// Created by ms0503 on 23/03/07.
//

#include "Motor.hh"
#include "MotorDriver.hpp"
#include "params.hh"

Motor::Motor(const MotorDriver &md) : _md(md) {
}

Motor::~Motor() = default;

void Motor::update(MotorState state) {
    _md.setDuty(ADDR_MOTOR_FL, state.FL);
    _md.setDuty(ADDR_MOTOR_FR, state.FR);
    _md.setDuty(ADDR_MOTOR_RL, state.RL);
    _md.setDuty(ADDR_MOTOR_RR, state.RR);
}
