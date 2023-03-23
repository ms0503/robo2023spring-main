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
    using GPIO::GPIO;

    explicit LED(Pin pin);

    /**
     * 消灯
     */
    inline void turnOff() {
        low(0);
    }
    /**
     * 点灯
     */
    inline void turnOn() {
        high(0);
    }
};

#endif // MAIN_LED_HH
