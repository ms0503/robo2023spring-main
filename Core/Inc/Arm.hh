//
// Created by ms0503 on 23/03/09.
//

#ifndef MAIN_ARM_HH
#define MAIN_ARM_HH

#include "LowLayer/GPIO.hh"
#include "params.hh"

/// 回収用アーム
class Arm : public LMLL::GPIO {
public:
    using LMLL::GPIO::GPIO;

    /**
     * コンストラクタ
     * @param pin GPIOピン情報
     */
    explicit Arm(Pin pin);

    /**
     * 掴む
     */
    void close() const;
    /**
     * 離す
     */
    void open() const;
};

#endif// MAIN_ARM_HH
