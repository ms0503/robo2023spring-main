//
// Created by ms0503 on 23/03/18.
//

#ifndef MAIN_LED_HH
#define MAIN_LED_HH

#include "LowLayer/GPIO.hh"
#include "params.hh"

/// GPIO制御のLED
class LED : LMLL::GPIO {
public:
    using LMLL::GPIO::GPIO;

    /**
     * コンストラクタ
     * @param pin GPIOピン情報
     */
    explicit LED(Pin pin);
    /**
     * 消灯
     */
    void turnOff() const;
    /**
     * 点灯
     */
    void turnOn() const;
};

#endif// MAIN_LED_HH
