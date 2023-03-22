//
// Created by ms0503 on 23/03/18.
//

#ifndef MAIN_LED_HH
#define MAIN_LED_HH

#include "LowLayer/GPIO.hh"
#include "params.hh"

/// GPIO制御のLED
class LED : public LMLL::GPIO {
public:
    using LMLL::GPIO::GPIO;

    /**
     * 消灯
     */
    void turnOff(std::size_t index) const;
    /**
     * 点灯
     */
    void turnOn(std::size_t index) const;
};

#endif // MAIN_LED_HH
