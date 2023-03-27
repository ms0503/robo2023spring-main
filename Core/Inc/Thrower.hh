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
    using GPIO::GPIO;

    explicit Thrower(const std::vector<Pin> &pin);

    /**
     * 発射
     */
    inline void dispatch() {
        low(LOADER_LEFT_INDEX);
        low(LOADER_RIGHT_INDEX);
    }
    /**
     * リロード
     */
    inline void reload() {
        high(LOADER_LEFT_INDEX);
        high(LOADER_RIGHT_INDEX);
    }
    /**
     * ロック
     */
    inline void lock() {
        high(LOCKER_INDEX);
    }
    /**
     * ロック解除
     */
    inline void unlock() {
        low(LOCKER_INDEX);
    }

private:
    static constexpr const std::size_t LOADER_LEFT_INDEX = 0;
    static constexpr const std::size_t LOADER_RIGHT_INDEX = 1;
    static constexpr const std::size_t LOCKER_INDEX = 2;
};

#endif // MAIN_THROWER_HH
