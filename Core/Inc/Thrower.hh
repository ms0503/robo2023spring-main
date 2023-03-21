//
// Created by ms0503 on 23/03/09.
//

#ifndef MAIN_THROWER_HH
#define MAIN_THROWER_HH

#include "LowLayer/GPIO.hh"
#include "params.hh"

/// 射出機構
class Thrower : public LMLL::GPIO {
public:
    using LMLL::GPIO::GPIO;

    /**
     * コンストラクタ
     * @param pin GPIOピン情報
     */
    explicit Thrower(Pin pin);
    /**
     * 発射
     */
    void dispatch() const;
    /**
     * リロード
     */
    void reload() const;
};

#endif // MAIN_THROWER_HH
