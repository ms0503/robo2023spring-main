//
// Created by ms0503 on 23/03/08.
//

#ifndef MAIN_CONTROLLER_HH
#define MAIN_CONTROLLER_HH

#include "Motor.hh"
#include <cstdint>
#include <map>
#include <string>

typedef struct {
    long double left;
    long double right;
} StickTheta;

class Controller {
public:
    Controller();
    ~Controller();
    static MotorState motor(int8_t leftX, int8_t leftY, int8_t rightX, int8_t rightY);

private:
    static const std::map<std::string, int8_t> DEAD_ZONES;

    static long double stickToTheta(int8_t x, int8_t y);
    static StickTheta sticksToTheta(int8_t leftX, int8_t leftY, int8_t rightX, int8_t rightY);
};

#endif //MAIN_CONTROLLER_HH
