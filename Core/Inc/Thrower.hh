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
     * 発射
     */
    void dispatch() const;
    /**
     * リロード
     */
    void reload() const;
    /**
     * ロック
     */
    void lock() const;
    /**
     * ロック解除
     */
    void unlock() const;

private:
    static constexpr const std::size_t LOADER_LEFT_INDEX = 0;
    static constexpr const std::size_t LOADER_RIGHT_INDEX = 1;
    static constexpr const std::size_t LOCKER_INDEX = 2;
};

#endif // MAIN_THROWER_HH
